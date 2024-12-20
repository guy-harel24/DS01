#include <iostream>
#include "AVL_Tree.h"

int main() {
    Avl_Tree<int, int> tree;
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.insert(10);
    tree.insert(10);
    tree.insert(6);
    tree.insert(6);
    tree.insert(6);
    tree.insert(6);
    tree.insert(6);

    tree.print();

}
