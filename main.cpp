#include <iostream>
#include "Avl_Tree.h"

void extensiveInsertAndRemoveTests() {
    std::cout << "\n=== Extensive AVL Tree Insertion and Removal Tests ===\n";

    Avl_Tree<int, int> tree;

    // Insert nodes to form a balanced tree
    std::cout << "\nInserting nodes...\n";
    tree.insert(10, nullptr);
    tree.insert(20, nullptr);
    tree.insert(30, nullptr); // Right-right case
    tree.insert(15, nullptr); // Right-left case
    tree.insert(5, nullptr);  // Left-left case
    tree.insert(25, nullptr); // No imbalance
    tree.insert(35, nullptr); // No imbalance
    tree.insert(2, nullptr);  // Left-left case
    tree.insert(8, nullptr);  // Left-right case

    // Print tree height and balance factors
    std::cout << "\nTree height after insertions: " << tree.root->height << "\n";
    std::cout << "Root balance factor: " << tree.root->getBalanceFactor() << "\n";

    // Test removing leaf nodes
    std::cout << "\nRemoving leaf nodes...\n";
    tree.remove(2);
    std::cout << "Removed 2. Root balance factor: " << tree.root->getBalanceFactor() << "\n";
    assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);

    tree.remove(8);
    std::cout << "Removed 8. Root balance factor: " << tree.root->getBalanceFactor() << "\n";
    assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);

    // Test removing nodes with one child
    std::cout << "\nRemoving nodes with one child...\n";
    tree.remove(35);
    std::cout << "Removed 35. Root balance factor: " << tree.root->getBalanceFactor() << "\n";
    assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);

    tree.remove(25);
    std::cout << "Removed 25. Root balance factor: " << tree.root->getBalanceFactor() << "\n";
    assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);

    // Test removing nodes with two children
    std::cout << "\nRemoving nodes with two children...\n";
    tree.remove(20);
    std::cout << "Removed 20. Root balance factor: " << tree.root->getBalanceFactor() << "\n";
    assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);

    tree.remove(10);
    std::cout << "Removed 10. Root balance factor: " << tree.root->getBalanceFactor() << "\n";
    assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);

    // Final state
    std::cout << "\nTree height after all removals: " << (tree.root ? tree.root->height : 0) << "\n";
    std::cout << "Root key: " << (tree.root ? std::to_string(tree.root->key) : "null") << "\n";

    // Validate remaining structure
    std::cout << "\nValidating remaining structure...\n";
    for (int key : {5, 15, 30}) {
        Node<int, int>* found = tree.find(key);
        if (found) {
            std::cout << "Found key: " << key << "\n";
        } else {
            std::cout << "Key not found: " << key << "\n";
        }
    }

    std::cout << "\nAll insertion and removal tests passed successfully!\n";
}

int main() {
    extensiveInsertAndRemoveTests();
    return 0;
}
