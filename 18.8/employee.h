#pragma once

#include "person.h"

class employee : public person {
protected:
    double salary;
    string position;
public:
    employee(void);

public:
    ~employee(void) override;

    void show() override;

    void input() override;

    employee(string, int, double, string);

    employee(const employee &);

    double get_salary() { return salary; }

    void set_salary(double s) { salary = s; }

    string get_position() { return position; }

    void set_position(string p) { position = p; }

    employee &operator=(const employee &);
};