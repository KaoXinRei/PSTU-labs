#pragma once

template<class T>
struct node {
    T data;
    node *next;

    explicit node(T n) {
        data = n;
        next = nullptr;
    };

    node(T n, node *p) {
        data = n;
        next = p;
    }
    ~node() {
        delete next;
    }
};

template<class T>
class Stack {
protected:
    node<T> *top_node;
public:
    Stack();

    ~Stack();

    explicit Stack(T);

    Stack(T, T *);

    T top();

    bool empty();

    void pop();

    void push(T);
};

template<class T>
Stack<T>::Stack() {
    top_node = nullptr;
}

template<class T>
Stack<T>::Stack(T n) {
    top_node = new node<T>(n);
}

template<class T>
Stack<T>::Stack(T n, T *s) {
    top_node = new node<T>(s[0]);
    for (int i = 1; i < n; ++i) {
        top_node = new node<T>(s[i], top_node);
    }
}

template<class T>
T Stack<T>::top() {
    return top_node->data;
}

template<class T>
void Stack<T>::pop() {
    if (top_node != nullptr) {
        node<T> *tmp = top_node;
        top_node = top_node->next;
    }
}

template<class T>
void Stack<T>::push(T t) {
    top_node = new node<T>(t, top_node);
}

template<class T>
Stack<T>::~Stack() {
    delete top_node;
}

template<class T>
bool Stack<T>::empty() {
    return top_node == nullptr;
}
