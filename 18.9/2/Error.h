#pragma once

#include <iostream>
#include <string>

class Error {
public:
    virtual void what() {};
};

class IndexError : public Error {
protected:
    string msg;
public:
    IndexError(){ msg = "Index Error\n"; }

    virtual void what() { cout << msg; }
};

class SizeError : public Error {
protected:
    string msg;
public:
    SizeError(){ msg = "Size Error\n"; }

    virtual void what() { cout << msg; }
};


class MaxSizeError : public SizeError {
protected:
    string msg_;
public:
    MaxSizeError(){
        SizeError();
        msg_ = "size>MAX SIZE\n";
    }

    virtual void what() { cout << msg << msg_; }
};

class IndexError1 : public IndexError {
protected:
    string msg_;
public:
    IndexError1(){
        IndexError();
        msg_ = "Index < 0\n";
    }

    virtual void what() { cout << msg << msg_; }
};

class IndexError2 : public IndexError {
protected:
    string msg_;
public:
    IndexError2(){
        IndexError();
        msg_ = "Index >= size\n";
    }

    virtual void what() { cout << msg << msg_; }
};