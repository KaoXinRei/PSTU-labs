#pragma once

#include <string>

class object {
public:
    object(void);

    virtual void show() = 0;

    virtual std::string get_name() = 0;

    virtual void input() = 0;

    virtual ~object(void);
};