#include "dialog.h"
#include "person.h"
#include "employee.h"
#include <iostream>

using namespace std;

dialog::dialog() : tree() {
    EndState = 0;
}

dialog::~dialog() {}

void dialog::GetEvent(TEvent &event) {
    string OpInt = "+-mszq";
    string s;
    string param;
    char code;
    cout << '>';
    cin >> s;
    code = s[0];
    if (OpInt.find(code) >= 0) {
        event.what = evMessage;
        switch (code) {
            case 'm':
                event.command = cmMake;
                break;
            case '+':
                event.command = cmAdd;
                break;
            case '-':
                event.command = cmDel;
                break;
            case 's':
                event.command = cmShow;
                break;
            case 'z':
                event.command = cmGet;
                break;
            case 'q':
                event.command = cmQuit;
                break;
        }
        if (s.length() > 1) {
            param = s.substr(1, s.length() - 1);
            int A = atoi(param.c_str());
            event.a = A;
        }
    } else {
        event.what = evNothing;
    }
}

int dialog::execute() {
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!valid());
    return EndState;
}

void dialog::HandleEvent(TEvent &event) {
    if (event.what == evMessage) {
        string name;
        switch (event.command) {
            case cmMake:
                for (int i = 0; i < event.a; ++i) {
                    object *ptr;
                    int input;
                    cout << "What object to create(1 - person, 2 - employee)? ";
                    cin >> input;
                    switch (input) {
                        case 1:
                            ptr = new person;
                            ptr->input();
                            break;
                        case 2:
                            ptr = new employee;
                            ptr->input();
                            break;
                    }
                    add(ptr);
                }
                ClearEvent(event);
                break;
            case cmAdd:
                int input;
                object *ptr;
                cout << "What object to add(1 - person, 2 - employee)? ";
                cin >> input;
                switch (input) {
                    case 1:
                        ptr = new person;
                        ptr->input();
                        break;
                    case 2:
                        ptr = new employee;
                        ptr->input();
                        break;
                }
                add(ptr);
                ClearEvent(event);
                break;
            case cmShow:
                show();
                ClearEvent(event);
                break;
            case cmDel:
                cout << "What person to delete(enter name)? ";
                cin >> name;
                del(name);
                ClearEvent(event);
                break;
            case cmQuit:
                EndExec();
                ClearEvent(event);
                break;
        }
    }
}

void dialog::ClearEvent(TEvent &event) {
    event.what = evNothing;
}

int dialog::valid() {
    if (EndState == 0) {
        return 0;
    } else {
        return 1;
    }
}

void dialog::EndExec() {
    EndState = 1;
}
