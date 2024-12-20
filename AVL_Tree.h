//
// Created by guyha on 20/12/2024.
//

#ifndef DATASTRUCTURE01_AVL_TREE_H
#define DATASTRUCTURE01_AVL_TREE_H

#include "Node.h"
#include <exception>
#include <stdexcept>
#include <iostream>

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
};


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
    delete root;
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
void insert_aux(Node<Key, T>* root, Key key, T* data) {
    if (key < root->key) {
        if (root->left_son == nullptr) {
            root->left_son = new Node<Key, T>(key, data, root);
        } else {
            insert_aux(root->left_son, key, data);
        }
    } else if (key > root->key) {
        if (root->right_son == nullptr) {
            root->right_son = new Node<Key, T>(key, data, root);
        } else {
            insert_aux(root->right_son, key, data);
        }
    }
}

template <typename Key, typename T>
void Avl_Tree<Key, T>::insert(Key key, T* data) {
    if (root == nullptr) {
        root = new Node<Key, T>(key, data, nullptr);
    } else if (find(key) == nullptr) {
        insert_aux(root, key, data);
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
void Avl_Tree<Key, T>::print(){ //in o
    printAux(root);
}

template<typename Key, typename T>
void Avl_Tree<Key, T>::remove(Key) {

}

template<typename Key, typename T>
void removeLeaf(Node<Key, T>* node) {
    delete node;
}

template<typename Key, typename T>
void removeHasOneSon(Node<Key, T>* node){

}

template<typename Key, typename T>
void removeHasTwoSons(Node<Key, T>* node){

}

#endif //DATASTRUCTURE01_AVL_TREE_H
