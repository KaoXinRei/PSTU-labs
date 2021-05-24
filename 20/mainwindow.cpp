#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new myGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    connect(ui->balancedTreeButton, &QPushButton::released, this, &MainWindow::create_b_tree);
    connect(ui->maximunButton, &QPushButton::released, this, &MainWindow::get_max);
    connect(ui->clearButton, &QPushButton::released, this, &MainWindow::clear);
    setStyleSheet("QWidget {background-color:#44556E}");
}

QString MainWindow::double_to_str(double in){
    QString result = QString::fromStdString(std::to_string(in));
    double intpart;
    while (result.back() == '0'){
        result.remove(result.length() - 1, 1);
    }
    if (modf(in, &intpart) == 0.0){
        result.remove(result.length() - 1, 1);
    }
    return result;
}


void MainWindow::get_max() {
    QMessageBox* dialog = new QMessageBox;
    if (tree.size() == 0) {
        dialog->setText("Нет дерева");
    } else {
        dialog->setText(double_to_str(tree[0].find_max()));
    }
    dialog->show();
}

void MainWindow::clear() {
    while (!cities.empty()) {
        delete cities[0];
        cities.erase(cities.begin());
    }
    while (!roads.empty()) {
        delete roads[0];
        roads.erase(roads.begin());
    }
    if (!tree.empty()){
        tree.pop_back();
    }
    scene->QGraphicsScene::update();
}

void MainWindow::create_b_tree() {
    QStringList leafs = ui->leafInput->text().split(' ');
    balanced_tree b_tree(leafs[0].toDouble());
    leafs.pop_front();
    for (auto leaf : leafs) {
        b_tree.add_leaf(leaf.toDouble());
    }
    add_node(b_tree, 0, 0);
    tree.push_back(b_tree);
}

city* MainWindow::add_node(balanced_tree t, int x, int y) {
    city *new_city = new city(double_to_str(t.get_item()), x, y);
    cities.push_back(new_city);
    scene->addItem(new_city);
    city* leaf_city;
    road* new_road;
    if (t.get_left() != nullptr) {
        if (t.get_right() == nullptr) {
            leaf_city = add_node(*t.get_left(), x - 50, y + 50);
            new_road = new road(new_city, leaf_city);
            roads.push_back(new_road);
            scene->addItem(new_road);
        } else {
            int dif = floor(log2(double(t.get_n_of_children()))) * 50 + t.get_n_of_children()*5;
            leaf_city = add_node(*t.get_left(), x - dif, y + 50);
            new_road = new road(new_city, leaf_city);
            roads.push_back(new_road);
            scene->addItem(new_road);
            leaf_city = add_node(*t.get_right(), x + dif, y + 50);
            new_road = new road(new_city, leaf_city);
            roads.push_back(new_road);
            scene->addItem(new_road);
        }
    }
    scene->QGraphicsScene::update();
    return new_city;
}

/*void MainWindow::add_city() {
    city *new_city = new city(ui->cityNameLine->text(), 0, 0);
    for (auto i : cities){
        if (*new_city == *i) {
            delete new_city;
            return;
        }
    }
    cities.push_back(new_city);
    scene->addItem(new_city);
    scene->QGraphicsScene::update();
}*/


MainWindow::~MainWindow()
{
    delete ui;
}

