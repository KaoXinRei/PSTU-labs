#include "tree.h"
#include <string>
#include <iostream>

using namespace std;

bool is_greater(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] > s2[i]) {
            return true;
        } else if (s1[i] != s2[i]) {
            return false;
        }
    }
    if (s1.size() > s2.size()) {
        return true;
    } else {
        return false;
    }
}

tree::tree(object *o) {
    item = o;
    left = nullptr;
    right = nullptr;
}

tree::~tree() {
    delete item;
    delete left;
    delete right;
}

void tree::add(object *o) {
    if (item == nullptr) {
        item = o;
        return;
    }
    if (is_greater(o->get_name(), item->get_name())) {
        if (right != nullptr) {
            right->add(o);
        } else {
            tree *branch = new tree(o);
            right = branch;
        }
    } else {
        if (left != nullptr) {
            left->add(o);
        } else {
            tree *branch = new tree(o);
            left = branch;
        }
    }
}

void tree::del(string n) {
    if (item->get_name() == n) {
        removeItem();
    } else if (left == nullptr && right == nullptr) {
        cout << "No such element found\n";
    } else {
        if (is_greater(n, item->get_name())) {
            if (right == nullptr) {
                cout << "No such element found\n";
                return;
            }
            if (right->item->get_name() == n) {
                removeRight();
            } else {
                right->del(n);
            }
        } else {
            if (left == nullptr) {
                cout << "No such element found\n";
                return;
            }
            if (left->item->get_name() == n) {
                removeLeft();
            } else {
                right->del(n);
            }
        }
    }
}

void tree::show() {
    if (left != nullptr) {
        left->show();
    }
    if (item != nullptr) {
        item->show();
    }
    if (right != nullptr) {
        right->show();
    }
}

void tree::removeItem() {
    if (right == nullptr && left == nullptr) {
        object* tmp = item;
        item = nullptr;
        delete tmp;
    } else if (right == nullptr) {
        object* tmp_o = item;
        delete tmp_o;
        tree *tmp = left;
        item = tmp->item;
        right = tmp->right;
        tmp->right = nullptr;
        left = tmp->left;
        tmp->left = nullptr;
        tmp->item = nullptr;
        delete tmp;
    } else if (left == nullptr) {
        object* tmp_o = item;
        delete tmp_o;
        tree *tmp = right;
        item = tmp->item;
        right = tmp->right;
        tmp->right = nullptr;
        left = tmp->left;
        tmp->left = nullptr;
        tmp->item = nullptr;
        delete tmp;
    } else {
        tree *m = right;
        if (m->left != nullptr) {
            while (m->left->left != nullptr) {
                m = m->left;
            }
            if (m->left->right == nullptr) {
                right->item = m->left->item;
                m->left->item = nullptr;
                delete m->left;
                m->left = nullptr;
            } else {
                right->item = m->left->item;
                tree *to_del = m->left;
                m->left = m->left->right;
                to_del->right = nullptr;
                to_del->item = nullptr;
                delete to_del;
            }
        } else {
            if (m->right == nullptr) {
                item = m->item;
                m->item = nullptr;
                delete m;
                right = nullptr;
            } else {
                item = m->item;
                right = right->right;
                m->right = nullptr;
                m->item = nullptr;
                delete m;
            }
        }
    }
}

void tree::removeRight() {
    if (right->right == nullptr && right->left == nullptr) {
        delete right;
        right = nullptr;
    } else if (right->right == nullptr) {
        delete right->item;
        tree *tmp = right->left;
        right->item = tmp->item;
        right->right = tmp->right;
        tmp->right = nullptr;
        right->left = tmp->left;
        tmp->left = nullptr;
        tmp->item = nullptr;
        delete tmp;
    } else if (right->left == nullptr) {
        delete right->item;
        tree *tmp = right->right;
        right->item = tmp->item;
        right->right = tmp->right;
        tmp->right = nullptr;
        right->left = tmp->left;
        tmp->left = nullptr;
        tmp->item = nullptr;
        delete tmp;
    } else {
        tree *m = right->right;
        if (m->left != nullptr) {
            while (m->left->left != nullptr) {
                m = m->left;
            }
            if (m->left->right == nullptr) {
                right->item = m->left->item;
                m->left->item = nullptr;
                delete m->left;
                m->left = nullptr;
            } else {
                right->item = m->left->item;
                tree *to_del = m->left;
                m->left = m->left->right;
                to_del->right = nullptr;
                to_del->item = nullptr;
                delete to_del;
            }
        } else {
            if (m->right == nullptr) {
                right->item = m->item;
                m->item = nullptr;
                delete m;
                right->right = nullptr;
            } else {
                right->item = m->item;
                right = right->right;
                m->right = nullptr;
                m->item = nullptr;
                delete m;
            }
        }
    }
}

void tree::removeLeft() {
    if (left->right == nullptr && left->left == nullptr) {
        delete left;
        left = nullptr;
    } else if (left->right == nullptr) {
        delete left->item;
        tree *tmp = left->left;
        left->item = tmp->item;
        left->right = tmp->right;
        tmp->right = nullptr;
        left->left = tmp->left;
        tmp->left = nullptr;
        delete tmp;
    } else if (left->left == nullptr) {
        delete left->item;
        tree *tmp = left->right;
        left->item = tmp->item;
        left->right = tmp->right;
        tmp->right = nullptr;
        left->left = tmp->left;
        tmp->left = nullptr;
        delete tmp;
    } else {
        tree *m = left->right;
        if (m->left != nullptr) {
            while (m->left->left != nullptr) {
                m = m->left;
            }
            if (m->left->right == nullptr) {
                left->item = m->left->item;
                m->left->item = nullptr;
                delete m->left;
                m->left = nullptr;
            } else {
                left->item = m->left->item;
                tree *to_del = m->left;
                m->left = m->left->right;
                to_del->right = nullptr;
                to_del->item = nullptr;
                delete to_del;
            }
        } else {
            if (m->right == nullptr) {
                left->item = m->item;
                m->item = nullptr;
                delete m;
                left->right = nullptr;
            } else {
                left->item = m->item;
                left = left->right;
                m->right = nullptr;
                m->item = nullptr;
                delete m;
            }
        }
    }
}

tree::tree() {
    item = nullptr;
    left = nullptr;
    right = nullptr;
}

