#pragma once

#include "event.h"
#include "tree.h"

class dialog : public tree {
public:
    dialog();

public:
    virtual ~dialog();

    virtual void GetEvent(TEvent &event);

    virtual int execute();

    virtual void HandleEvent(TEvent &event);

    virtual void ClearEvent(TEvent &event);

    int valid();

    void EndExec();

protected:
    int EndState;
};