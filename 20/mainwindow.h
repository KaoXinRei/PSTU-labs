#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "city.h"
#include <QGraphicsView>
#include <vector>
#include "road.h"
#include "mygraphicsscene.h"
#include <QKeyEvent>
#include <QDoubleValidator>
#include "balanced_tree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    city* add_node(balanced_tree, int, int);
    QString double_to_str(double);

private slots:
    void create_b_tree();
    void get_max();
    void clear();

private:
    Ui::MainWindow *ui;
    myGraphicsScene* scene;
    std::vector<city*> cities;
    std::vector<road*> roads;
    std::vector<balanced_tree> tree;

};
#endif // MAINWINDOW_H
