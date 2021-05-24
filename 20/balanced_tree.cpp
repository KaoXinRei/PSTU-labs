#include "balanced_tree.h"
#include <algorithm>

balanced_tree::balanced_tree(double i) {
    left = nullptr;
    right = nullptr;
    item = i;
    num_of_children = 0;
}

void balanced_tree::add_leaf(double l) {
    if (left == nullptr) {
        balanced_tree* leaf = new balanced_tree(l);
        left = leaf;
    } else if (right == nullptr) {
        balanced_tree* leaf = new balanced_tree(l);
        right = leaf;
    } else if (left->num_of_children > right->num_of_children) {
        right->add_leaf(l);
    } else {
        left->add_leaf(l);
    }
    ++num_of_children;
}

double balanced_tree::get_item() {
    return item;
}

double balanced_tree::find_max() {
    if (right == nullptr && left == nullptr) {
        return item;
    } else if (right == nullptr) {
        return std::max(item, left->find_max());
    } else {
        return std::max({item, left->find_max(), right->find_max()});
    }
}

int balanced_tree::get_n_of_children() {
    return num_of_children;
}

balanced_tree* balanced_tree::get_left() {
    return left;
}

balanced_tree* balanced_tree::get_right() {
    return right;
}

