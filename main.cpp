#include <iostream>
#include "AVL_Tree.h"

int main() {
    Avl_Tree<int, std::string> tree;
    // Test 1: Insert nodes
    tree.insert(10, new std::string("Root"));
    tree.insert(5, new std::string("Left Child"));
    tree.insert(15, new std::string("Right Child"));
    tree.insert(3, new std::string("Left Grandchild"));
    tree.insert(7, new std::string("Right Grandchild"));
    tree.insert(13, new std::string("Left Grandchild of Right"));
    tree.insert(17, new std::string("Right Grandchild of Right"));

    // Print the tree (in-order traversal)
    std::cout << "Tree after insertions (in-order): ";
    tree.print();

    // Test 2: Remove a leaf node
    std::cout << "Removing leaf node (17)...\n";
    tree.remove(17);
    std::cout << "Tree after removing leaf node: ";
    tree.print();

    // Test 3: Remove a node with one child
    std::cout << "Removing node with one child (15)...\n";
    tree.remove(15);
    std::cout << "Tree after removing node with one child: ";
    tree.print();

    // Test 4: Remove a node with two children
    std::cout << "Removing node with two children (10)...\n";
    tree.remove(10);
    std::cout << "Tree after removing node with two children: ";
    tree.print();

    // Test 5: Remove root node (special case)
    std::cout << "Removing root node (5)...\n";
    tree.remove(5);
    std::cout << "Tree after removing root node: ";
    tree.print();

    // Test 6: Attempt to remove a non-existent node
    try {
        std::cout << "Attempting to remove non-existent node (42)...\n";
        tree.remove(42);
    } catch (const std::logic_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

}
