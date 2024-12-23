//
// Created by guyha on 20/12/2024.
//

#ifndef DATASTRUCTURE01_NODE_H
#define DATASTRUCTURE01_NODE_H
const int LEAVE_HEIGHT = 0;

template <typename Key, typename T>
struct Node {
    Key key;
    T* data;
    int height;
    Node* father = nullptr;
    Node* left_son = nullptr;
    Node* right_son = nullptr;

    explicit Node(int key) : key(key), height(LEAVE_HEIGHT) {}
    Node(int key, T* value) : key(key), data(value), height(LEAVE_HEIGHT) {}
    Node(int key, T* value, Node* father)
            :   key(key), data(value), father (father), height(LEAVE_HEIGHT) {}

    ~Node() { delete data;}  // Ensure proper cleanup

    int getBalanceFactor() const;
    void updateHeightInNode();
};

template<typename Key, typename T>
void Node<Key, T>::updateHeightInNode() {
    int left_height = -1, right_height = -1;
    if(left_son){
        left_height = left_son->height;
    }
    if(right_son){
        right_height = right_son->height;
    }
    int new_height = right_height > left_height ? right_height : left_height;
    new_height++;
    height = new_height;
}

template<typename Key, typename T>
int Node<Key, T>::getBalanceFactor() const {
    int left_height = -1, right_height = -1;
    if(left_son) {
        left_height = left_son->height;
    }
    if (right_son){
        right_height = right_son->height;
    }
    return left_height - right_height;
}


#endif //DATASTRUCTURE01_NODE_H
