#ifndef SOLUTION_H
#define SOLUTION_H

#include <QDialog>
#include <vector>
#include "city.h"
#include "road.h"

namespace Ui {
class solution;
}

class solution : public QDialog
{
    Q_OBJECT

public:
    explicit solution(std::vector<city*>, std::vector<road*>,
                      QString, QWidget *parent = nullptr);
    ~solution();

private:
    void solve(std::vector<std::vector<double>>, int);
    QString double_to_str(double);

private slots:
    void close();

private:
    Ui::solution *ui;
    std::vector<QString> city_names;
    std::vector<std::vector<double>> matrix;
    QString solution_text;

};

#endif // SOLUTION_H
