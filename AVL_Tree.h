//
// Created by guyha on 20/12/2024.
//

#ifndef DATASTRUCTURE01_AVL_TREE1_H
#define DATASTRUCTURE01_AVL_TREE1_H

#include "Node.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <cassert>


template <typename Key, typename T>
class Avl_Tree
{
public:
    Node<Key,T>* root;
    Avl_Tree() : root(nullptr){};
    ~Avl_Tree();
    Node<Key, T>* find(Key);
    void insert(Key, T* data = nullptr);
    void remove(Key);
    void print();
    int getHeight() const;

};
enum Operation {Remove, Insert};

template<typename Key, typename T>
int Avl_Tree<Key, T>::getHeight() const {
    if(root){
        return root->height;
    }
    return LEAVE_HEIGHT - 1;

}


template<typename Key, typename T>
Avl_Tree<Key, T>::~Avl_Tree() {
    deleteTree(root);
}

template <typename Key, typename T = std::less<Key>>
void deleteTree(Node<Key,T>* root){
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left_son);
    deleteTree(root->right_son);
    Node<Key,T>* tmp = root;
    root = nullptr;
    delete tmp;
}




template <typename Key, typename T>
Node<Key, T>* findAux(Node<Key, T>* root, Key key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (key < root->key) {
        return findAux(root->left_son, key); // Propagate return value
    } else if (key > root->key) {
        return findAux(root->right_son, key); // Propagate return value
    } else {
        return root;
    }
}

template <typename Key, typename T>
Node<Key, T>* Avl_Tree<Key, T>::find(Key key) {
    return findAux(root, key);
}

template <typename Key, typename T>
void updateHeightInTree(Node<Key, T>* node){
    while (node){
        int left_height = -1, right_height = -1;
        if(node->left_son){
            left_height = node->left_son->height;
        }
        if(node->right_son){
            right_height = node->right_son->height;
        }
        int new_height = right_height > left_height ? right_height : left_height;
        new_height++;
        if (new_height == node->height){
            break;
        }
        node->height = new_height;
        node = node->father;
    }
}

template <typename Key, typename T>
void balanceLL(Node<Key, T>* node, Avl_Tree<Key, T>* tree) {
   // assert(node->getBalanceFactor() == 2);
   // assert(node->left_son->getBalanceFactor() >= 0);
    Node<Key, T>* father = node;
    Node<Key, T>* son = node->left_son;
    Node<Key, T>* right_grandson = son->right_son;

    // Perform rotation
    son->right_son = father;
    father->left_son = right_grandson;


    // Update parent relationships
    if (right_grandson) {
        right_grandson->father = father;
    }
    if (father->father) {
        son->father = father->father;
        if (father->father->left_son == father) {
            father->father->left_son = son;
        } else {
            father->father->right_son = son;
        }
    } else { // father is root
        son->father = nullptr;
        tree->root = son;
    }
    father->father = son;

    // Update heights
    father->updateHeightInNode();
    son->updateHeightInNode();
}

template <typename Key, typename T>
void balanceRR(Node<Key, T>* node, Avl_Tree<Key, T>* tree) {
  //  assert(node->getBalanceFactor() == -2);
  //  assert(node->right_son->getBalanceFactor()== -1);
    Node<Key, T>* father = node;
    Node<Key, T>* son = node->right_son;
    Node<Key, T>* left_grandson = son->left_son;

    // Perform rotation
    son->left_son = father;
    father->right_son = left_grandson;

    // Update parent relationships
    if (left_grandson) {
        left_grandson->father = father;
    }
    if (father->father) {
        son->father = father->father;
        if (father->father->left_son == father) {
            father->father->left_son = son;
        } else {
            father->father->right_son = son;
        }
    } else { // father is root
        son->father = nullptr;
        tree->root = son;
    }
    father->father = son;

    // Update heights
    father->updateHeightInNode();
    son->updateHeightInNode();
}

template <typename Key, typename T>
void balanceLR(Node<Key, T>* node, Avl_Tree<Key, T>* tree) {
    assert(node->getBalanceFactor() == 2);
    assert(node->left_son->getBalanceFactor() == -1);
    balanceRR(node->left_son, tree);
    balanceLL(node, tree);
}

template <typename Key, typename T>
void balanceRL(Node<Key, T>* node, Avl_Tree<Key, T>* tree) {
    assert(node->getBalanceFactor() == -2);
    assert(node->right_son->getBalanceFactor() >= 0);
    balanceLL(node->right_son, tree);
    balanceRR(node, tree);
}


template <typename Key, typename T>
void balanceAfterOperation(Avl_Tree<Key, T>* tree,
                           Node<Key,T>* node, Operation operation){
    while(node){
        if(node->getBalanceFactor() == 2){
            assert(node->left_son);
            if(node->left_son->getBalanceFactor() >= 0) {
                balanceLL(node, tree);
            } else {
                balanceLR(node, tree);
            }
            if(operation == Insert){
                break;
            }
        } else if (node->getBalanceFactor() == -2){
            assert(node->right_son);
            if(node->right_son->getBalanceFactor() == -1){
                balanceRR(node, tree);
            } else {
                balanceRL(node, tree);
            }
            if(operation == Insert){
                break;
            }
        }
        node = node->father;
    }
}
/*
template <typename Key, typename T>
void insertAux(Node<Key, T>* root, Key key, T* data) {
    if (key < root->key) {
        if (root->left_son == nullptr) {
            root->left_son = new Node<Key, T>(key, data, root);
            updateHeightInTree(root);
        } else {
            insertAux(root->left_son, key, data); // Propagate return value
        }
    } else if (key > root->key) {
        if (root->right_son == nullptr) {
            root->right_son = new Node<Key, T>(key, data, root);
            updateHeightInTree(root);
        } else {
            insertAux(root->right_son, key, data); // Propagate return value
        }
    }
}
*/

template <typename Key, typename T>
Node<Key, T>* insertAux(Node<Key, T>* root, Key key, T* data) {
    if (key < root->key) {
        if (root->left_son == nullptr) {
            root->left_son = new Node<Key, T>(key, data, root);
            updateHeightInTree(root);
            return root->left_son;
        } else {
            return insertAux(root->left_son, key, data); // Propagate return value
        }
    } else if (key > root->key) {
        if (root->right_son == nullptr) {
            root->right_son = new Node<Key, T>(key, data, root);
            updateHeightInTree(root);
            return root->right_son;
        } else {
            return insertAux(root->right_son, key, data); // Propagate return value
        }
    }
    return nullptr; // Should never reach here
}


template <typename Key, typename T>
void Avl_Tree<Key, T>::insert(Key key, T* data) {
    if (root == nullptr) {
        root = new Node<Key, T>(key, data, nullptr);
    } else if (find(key) == nullptr) {
        Node<Key,T>* inserted_node = insertAux(root, key, data);
        balanceAfterOperation(this, inserted_node, Insert);
    }
}

template <typename Key, typename T>
void printAux(Node<Key, T>* root){
    if (root == nullptr){
        return;
    }
    printAux(root->left_son);
    std::cout << root->key << " ";
    printAux(root->right_son);
}

template <typename Key, typename T>
void Avl_Tree<Key, T>::print(){//in order
    if (root) {
        printAux(root);
        std::cout << std::endl;
    }
}

template<typename Key, typename T>
void removeLeaf(Node<Key, T>* node) {
    if (node->father) { // If the node has a parent
        if (node->father->left_son == node) {
            node->father->left_son = nullptr; // Disconnect left child
        } else if (node->father->right_son == node) {
            node->father->right_son = nullptr; // Disconnect right child
        }
    }
    updateHeightInTree(node->father);
    delete node;
}

template<typename Key, typename T>
void removeRoot(Avl_Tree<Key, T>* tree){
    Node<Key, T>* tmp = tree->root;
    tree->root = nullptr;
    delete tmp;
}

template<typename Key, typename T>
void removeHasOneSon(Avl_Tree<Key, T>* tree, Node<Key, T>* node){
    Node<Key, T>* son = nullptr;
    if (node->left_son) {
        son = node->left_son;
        node->left_son->father = node->father;
    } else {
        son = node->right_son;
        node->right_son->father = node->father;
    }
    if (node->father) {
        if (node->father->left_son == node) {
            node->father->left_son = son;
        } else {
            node->father->right_son = son;
        }
        updateHeightInTree(node->father);
    } else {
        tree->root = son;
    }
    delete node;

}

template<typename Key, typename T>
bool isLeaf(Node<Key, T>* node)
{
    return !(node->left_son || node->right_son);
}

template<typename Key, typename T>
void removeHasTwoSons(Avl_Tree<Key, T>* tree, Node<Key, T>* node) {
    Node<Key, T> *replacement_node = node->right_son;
    while (replacement_node->left_son) {
        replacement_node = replacement_node->left_son;
    }
    node->key = replacement_node->key;
    delete node->data;
    node->data = replacement_node->data;
    replacement_node->data = nullptr;
    if (isLeaf(replacement_node)) {
        removeLeaf(replacement_node);
    } else {
        removeHasOneSon(tree, replacement_node);
    }
}
template<typename Key, typename T>
void Avl_Tree<Key, T>::remove(Key key) {
        Node<Key, T>* node = find(key);
        if (node) {
            Node<Key, T>* father = node->father;
            if (isLeaf(node)) {
                if(node->father) {
                    removeLeaf(node);
                } else {
                    removeRoot(this);
                }
            } else if (node->right_son && node->left_son) {
                removeHasTwoSons(this, node);
            } else {
                removeHasOneSon(this, node);
            }
            if (father) {
                balanceAfterOperation(this, father, Remove);
            } else {
                balanceAfterOperation(this, root, Remove);
            }
        }
    }

#endif //DATASTRUCTURE01_AVL_TREE1_H
