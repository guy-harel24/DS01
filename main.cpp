#include <iostream>
#include <vector>
#include "Avl_Tree.h"

void edgeCaseInsertAndRemoveTests() {
    std::cout << "\n=== Edge Case AVL Tree Insertion and Removal Tests ===\n";

    Avl_Tree<int, int> tree;

    // Insert a large set of nodes
    std::cout << "\nInserting multiple nodes...\n";
    std::vector<int> values = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
    for (int value : values) {
        tree.insert(value, nullptr);
        std::cout << "Inserted: " << value << ", Root: " << tree.root->key << ", Height: " << tree.root->height << "\n";
        assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);
    }

    // Print tree height and balance factor
    std::cout << "\nTree height after insertions: " << tree.root->height << "\n";
    std::cout << "Root balance factor: " << tree.root->getBalanceFactor() << "\n";

    // Remove the root repeatedly
    std::cout << "\nRemoving the root repeatedly...\n";
    while (tree.root) {
        int rootKey = tree.root->key;
        tree.remove(rootKey);
        std::cout << "Removed root: " << rootKey << ", New Root: "
                  << (tree.root ? std::to_string(tree.root->key) : "null")
                  << ", Height: " << (tree.root ? tree.root->height : 0) << "\n";
        if (tree.root) {
            assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);
        }
    }

    // Insert nodes again to test reusability
    std::cout << "\nReinserting nodes...\n";
    for (int value : values) {
        tree.insert(value, nullptr);
        std::cout << "Inserted: " << value << ", Root: " << tree.root->key << ", Height: " << tree.root->height << "\n";
        assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);
    }

    // Remove all nodes
    std::cout << "\nRemoving all nodes...\n";
    for (int value : values) {
        tree.remove(value);
        std::cout << "Removed: " << value << ", Root: "
                  << (tree.root ? std::to_string(tree.root->key) : "null")
                  << ", Height: " << (tree.root ? tree.root->height : 0) << "\n";
        if (tree.root) {
            assert(tree.root->getBalanceFactor() >= -1 && tree.root->getBalanceFactor() <= 1);
        }
    }

    // Final state
    std::cout << "\nTree height after all removals: " << (tree.root ? tree.root->height : 0) << "\n";
    std::cout << "Root key: " << (tree.root ? std::to_string(tree.root->key) : "null") << "\n";

    // Edge case: remove from an empty tree
    std::cout << "\nTesting removal from an empty tree...\n";
    try {
        tree.remove(10); // Attempt to remove from empty tree
        std::cout << "No exception raised when removing from empty tree.\n";
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\nAll edge case tests passed successfully!\n";
}

int main() {
    edgeCaseInsertAndRemoveTests();
    return 0;
}
