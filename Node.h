//
// Created by guyha on 20/12/2024.
//

#ifndef DATASTRUCTURE01_NODE_H
#define DATASTRUCTURE01_NODE_H

template <typename Key, typename T>
struct Node {
    Key key;
    T* data;
    Node* father = nullptr;
    Node* left_son = nullptr;
    Node* right_son = nullptr;

    explicit Node(int key) : key(key) {}
    Node(int key, T* value) : key(key), data(value) {}
    Node(int key, T* value, Node* father)
            :   key(key), data(value), father (father) {}

    ~Node() { delete data; }  // Ensure proper cleanup
};


#endif //DATASTRUCTURE01_NODE_H
