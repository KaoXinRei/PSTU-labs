#ifndef BALANCED_TREE_H
#define BALANCED_TREE_H


class balanced_tree
{
public:
    balanced_tree(double);
    void add_leaf(double);
    double get_item();
    double find_max();
    int get_n_of_children();
    balanced_tree* get_left();
    balanced_tree* get_right();

private:
    balanced_tree* left;
    balanced_tree* right;
    double item;
    int num_of_children;

};

#endif // BALANCED_TREE_H
