#include <iostream>
#include "Avl_Tree.h"

void testInsertHeight() {
    std::cout << "Testing Insert and Height Updates...\n";
    Avl_Tree<int, int> tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    // Check heights
    std::cout << "Height of root (10): " << tree.root->height << " (Expected: 2)\n";
    std::cout << "Height of left child (5): " << tree.root->left_son->height << " (Expected: 1)\n";
    std::cout << "Height of right child (15): " << tree.root->right_son->height << " (Expected: 1)\n";
    std::cout << "Height of leaf node (3): " << tree.root->left_son->left_son->height << " (Expected: 0)\n";
}

void testRemoveHeight() {
    std::cout << "\nTesting Remove and Height Updates...\n";
    Avl_Tree<int, int> tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    // Remove a leaf node
    tree.remove(3);
    std::cout << "Height after removing leaf (3): " << tree.root->left_son->height << " (Expected: 1)\n";

    // Remove a node with one child
    tree.remove(15);
    std::cout << "Height after removing node with one child (15): " << tree.root->height << " (Expected: 2)\n";

    // Remove the root
    tree.remove(10);
    std::cout << "Height after removing root (10): " << tree.root->height << " (Expected: 1)\n";
}

void testEdgeCases() {
    std::cout << "\nTesting Edge Cases...\n";
    Avl_Tree<int, int> tree;

    // Insert nodes to create an imbalanced tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(12);
    tree.insert(20);

    // Remove a node that causes height adjustments across multiple levels
    tree.remove(5);
    std::cout << "Height after removing node (5): " << tree.root->height << " (Expected: 2)\n";
    std::cout << "Height of root (10): " << tree.root->height << " (Expected: 2)\n";
    std::cout << "Height of right child (15): " << tree.root->right_son->height << " (Expected: 1)\n";

    // Remove all nodes and ensure heights are properly updated
    tree.remove(10);
    tree.remove(15);
    tree.remove(12);
    tree.remove(20);
    std::cout << "Tree height after removing all nodes: ";
    if (tree.root == nullptr) {
        std::cout << "Empty tree (Expected: Empty tree)\n";
    } else {
        std::cout << tree.root->height << " (Unexpected: Non-empty tree)\n";
    }
}

int main() {
    testInsertHeight();
    testRemoveHeight();
    testEdgeCases();

    return 0;
}
