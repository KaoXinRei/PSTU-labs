#include "solution.h"
#include "ui_solution.h"
#include <algorithm>
#include <QFileDialog>
#include <QMessageBox>
#include <queue>

solution::solution(std::vector<city*> cities, std::vector<road*> roads,
                   QString starting_city, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::solution)
{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::released, this, &solution::close);
    int n = 0;
    for (auto i : cities) {
        city_names.push_back(i->name);
        matrix.emplace_back();
        for (int j = 0; j < n; ++j) {
            matrix[n].push_back(-1);
        }
        for (int j = 0; j < n + 1; ++j) {
            matrix[j].push_back(-1);
        }
        ++n;
    }
    for (auto i : roads) {
        int first_city_index = std::distance(city_names.begin(),
                                             std::find(city_names.begin(),
                                                       city_names.end(),
                                                       i->first_city->name));
        int second_city_index = std::distance(city_names.begin(),
                                             std::find(city_names.begin(),
                                                       city_names.end(),
                                                       i->second_city->name));
        matrix[first_city_index][second_city_index] = i->length;
    }
    int s_city_num = 0;
    for (; s_city_num < city_names.size(); ++s_city_num) {
        if (city_names[s_city_num] == starting_city) {
            break;
        }
    }
    solve(matrix, s_city_num);
    ui->solutionBrowser->setText(solution_text);
}


QString solution::double_to_str(double in){
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

void solution::solve(std::vector<std::vector<double>> matrix,
                                 int starting_city){
    std::priority_queue<std::pair<double, int>> queue;
    std::vector<std::vector<int>> came_from;
    queue.push(std::make_pair(0, starting_city));
    std::vector<double> cost;
    for (int i = 0; i < matrix.size(); ++i) {
        cost.push_back(INFINITY);
        came_from.emplace_back();
    }
    cost[starting_city] = 0;
    while (!queue.empty()) {
        int cur = queue.top().second;
        queue.pop();
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[cur][i] != -1) {
                double ncost = cost[cur] + matrix[cur][i];
                if (ncost < cost[i]) {
                    cost[i] = ncost;
                    queue.push(std::make_pair(ncost, i));
                    came_from[i] = came_from[cur];
                    came_from[i].push_back(i);
                }
            }
        }
    }
    solution_text = "";
    for (int i = 0; i < cost.size(); ++i) {
        if (i != starting_city) {
            if (cost[i] == INFINITY) {
                solution_text += "До города " + city_names[i] + " добраться нельзя.\n";
                continue;
            }
            solution_text += "Расстояние до города " + city_names[i] + " равно: " + double_to_str(cost[i]);
            solution_text += ". Путь: ";
            for (auto city : came_from[i]) {
                solution_text += "->" + city_names[city];
            }
            solution_text += '\n';
        }
    }
}

void solution::close() {
    solution::~solution();
}

solution::~solution()
{
    delete ui;
}
