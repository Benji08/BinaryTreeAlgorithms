#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <ostream>
#include <iomanip>
#include "iostream"


template<typename KeyType, typename ValueType>
class AVLTree;

template<typename KeyType, typename ValueType>
class AVLTreeNode{
    friend class AVLTree<KeyType, ValueType>;

public:
    KeyType key;
    ValueType value;
    AVLTreeNode *left;
    AVLTreeNode *right;
    AVLTreeNode *parent;
    int height;
    int balance;


    AVLTreeNode(KeyType key, ValueType value){
        this->value = value;
        this->key = key;
        left = NULL;
        right = NULL;
        parent = NULL;
        balance = 0;
        height = 0;
    }

    ~AVLTreeNode(){
        this->key = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
        balance = 0;
        height = 0;
    }

    void setHeight(){
        int lsht = -1;
        if (left != NULL) {
            lsht = left->height;
        }
        int rsht = -1;
        if (right != NULL) {
            rsht = right->height;
        }
        if (lsht > rsht) {
            height = lsht + 1;
        } else {
            height = rsht + 1;
        }
    }

    void setBalance(){
        int lsht = -1;
        if (left != NULL) {
            lsht = left->height;
        }
        int rsht = -1;
        if (right != NULL) {
            rsht = right->height;
        }
        balance = lsht - rsht;
    }

    void inOrder(){
        if (this != NULL) {
            left->inOrder();
            std::cout << "Key : " << key
                      << "  Balance Factor : " << balance
                      << " Height " << height << std::endl;
            right->inOrder();
        }
    }

    size_t size2() const {
        if (this == NULL)
            return 0;
        else {
            return 1 + this->left->size2() + this->right->size2();
        }
    }

    std::string toString(){
        AVLTreeNode* node = this;
        std::stringstream localStream;

        localStream << "(" << "[" << node->key << "," << node->value << "],";
        if (node->left != NULL)
            localStream << node->left->toString();
        localStream << ",";
        if (node->right != NULL)
            localStream << node->right->toString();
        localStream << ")";
        return localStream.str();
    }

};


template <typename KeyType, typename ValueType>
class AVLTree{
private:
    AVLTreeNode <KeyType , ValueType>*root;
    using AVLTreeNode = AVLTreeNode<KeyType, ValueType>;
protected:
    void llRotation(AVLTreeNode *unbalanced){
        AVLTreeNode *rightChild;
        AVLTreeNode *node;

        node = unbalanced->left;
        rightChild = node->right;
        node->parent = unbalanced->parent;
        if (unbalanced == root) {
            root = node;
        } else {
            if (unbalanced->parent->left == unbalanced)
                unbalanced->parent->left = node;
            else
                unbalanced->parent->right = node;
        }
        unbalanced->left = rightChild;
        unbalanced->parent = node;
        node->right = unbalanced;
        if (rightChild != NULL)
            rightChild->parent = unbalanced;
        return;
    }

    void rrRotation(AVLTreeNode *unbalanced){
        AVLTreeNode *leftChild;
        AVLTreeNode *node;
        node = unbalanced->right;
        leftChild = node->left;
        node->parent = unbalanced->parent;
        if (unbalanced == root) {
            root = node;
        } else {
            if (unbalanced->parent->left == unbalanced)
                unbalanced->parent->left = node;
            else
                unbalanced->parent->right = node;
        }
        unbalanced->right = leftChild;
        unbalanced->parent = node;
        node->left = unbalanced;
        if (leftChild != NULL) {
            leftChild->parent = unbalanced;
        }
        return;
    }

    void rlRotation(AVLTreeNode *unbalanced){
        AVLTreeNode *node = unbalanced->right;
        llRotation(node);
        restoreBalance(node);
        rrRotation(unbalanced);
        return;
    }

    void lrRotation(AVLTreeNode *unbalanced){
        AVLTreeNode *node = unbalanced->left;
        rrRotation(node);
        restoreBalance(node);
        llRotation(unbalanced);
        return;
    }

    void restoreBalance(AVLTreeNode *node){
        if (node != NULL) {
            node->setHeight();
            node->setBalance();
            restoreBalance(node->parent);
        }
        return;
    }

    void balanceTree(AVLTreeNode *start, AVLTreeNode *unbalanced){
        if (unbalanced == NULL) {
            restoreBalance(start);
            return;
        }
        if (unbalanced->balance == -2) {
            if (unbalanced->right->key < start->key)
                rrRotation(unbalanced);
            else
                rlRotation(unbalanced);
        } else {
            if (unbalanced->balance == 2) {
                if (unbalanced->left->key > start->key)
                    llRotation(unbalanced);
                else
                    lrRotation(unbalanced);
            }
        }
        restoreBalance(unbalanced);
        return;
    }

    void clearTree(AVLTreeNode *n){
        if(n!=NULL){
            clearTree(n->left);
            clearTree(n->right);
            delete n;
        }
    }

public:
    int size(){
        if(this->root == NULL)
            return 0;
        else
            return this->root->height;
    }

    size_t size2() const{
        AVLTreeNode *temp = root;
        if(root == NULL)
            return 0;
        else {
            return 1 + temp->left->size2() + temp->right->size2();
        }
    }

    AVLTree(){
        root = NULL;
    }

    ~AVLTree(){
        clearTree(root);
    }

    void add(KeyType key, ValueType value){
        AVLTreeNode* newNode = new AVLTreeNode(key, value);
        AVLTreeNode *temp = root;
        AVLTreeNode *unbalanced = NULL;
        if(root == NULL){
            root = newNode;
            return;
        }
        while (true){
            if(newNode->key == temp->key){
            temp->value = value;
            }
            if (temp->balance != 0) {
                unbalanced = temp;
            }
            if (newNode->key < temp->key) {
                /* if the left subtree is empty */
                if (temp->left == NULL) {
                    /*make new node the left child */
                    temp->left = newNode;
                    break;
                } else { //traverse to left sub tree
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
        newNode->parent = temp;
        restoreBalance(newNode);
        balanceTree(newNode, unbalanced);
        return;
    }

    void remove(KeyType key){
        AVLTreeNode* temp = root;
        AVLTreeNode* temp_parent = temp;
        bool side;
        while (true){
            if(temp->key == key){
                if(temp->right == NULL && temp->left == NULL && side ==1){
                    temp_parent->right = NULL;
                    restoreBalance(temp);
                    balanceTree(temp, root);
                    return;
                }
                else if(temp->right == NULL && temp->left == NULL && side ==0){
                    temp_parent->left = NULL;
                    restoreBalance(temp);
                    balanceTree(temp, temp_parent);
                    return;
                }
                else if(temp->right == NULL && side ==0){
                    temp_parent->left = temp->left;
                    temp->left->parent = temp_parent;
                    restoreBalance(temp);
                    balanceTree(temp, root);
                    return;
                }
                else if(temp->left == NULL && side ==0){
                    temp_parent->left = temp->right;
                    temp->right->parent = temp_parent;
                    restoreBalance(temp);
                    balanceTree(temp, root);
                    return;
                }
                else if(temp->right == NULL && side ==1){
                    temp_parent->right = temp->left;
                    temp->left->parent = temp_parent;
                    restoreBalance(temp);
                    balanceTree(temp, root);
                    return;
                }
                else if(temp->right == NULL && side ==0){
                    temp_parent->right = temp->right;
                    temp->right->parent = temp_parent;
                    restoreBalance(temp);
                    balanceTree(temp, root);
                    return;
                }
                else if(temp->right !=NULL && temp->left !=NULL && side ==0){
                    AVLTreeNode* new_temp = temp->left;
                    AVLTreeNode* new_temp_parent = temp;
                    while(new_temp->right != NULL) {
                        new_temp_parent = new_temp;
                        new_temp = new_temp->right;
                    }
                    temp_parent->left = new_temp;
                    if(new_temp != temp->left) {
                        new_temp->left = temp->left;
                        temp->left->parent = new_temp;
                    }
                    else
                        new_temp->left = NULL;
                    new_temp->parent = temp_parent;
                    new_temp->right = temp->right;
                    temp->right->parent = new_temp;
                    new_temp_parent->right = NULL;
                    restoreBalance(new_temp);
                    balanceTree(root, new_temp);
                    return;
                }
                else if(temp->right !=NULL && temp->left !=NULL && side ==1){
                    AVLTreeNode* new_temp = temp->left;
                    AVLTreeNode* new_temp_parent = temp;
                    while(new_temp->right != NULL) {
                        new_temp_parent = new_temp;
                        new_temp = new_temp->right;
                    }
                    temp_parent->right = new_temp;
                    if(new_temp != temp->left) {
                        new_temp->left = temp->left;
                        temp->left->parent = new_temp;
                    }
                    else
                        new_temp->left = NULL;
                    new_temp->parent = temp_parent;
                    new_temp->right = temp->right;
                    temp->right->parent = new_temp;
                    new_temp_parent->right = NULL;
                    restoreBalance(new_temp);
                    balanceTree(root , new_temp);
                    return;
                }
            }
            else if(temp->right == NULL && temp->left == NULL){
                return;
            }
            else if(temp->key < key){
                if(temp->right == NULL)
                    return;
                temp_parent = temp;
                temp = temp->right;
                side = true;
            }
            else if(temp->key > key){
                if(temp->left == NULL)
                    return;
                temp_parent = temp;
                temp = temp->left;
                side = false;
            }
        }
    }

    void inOrder(){
        std::cout << std::endl;
        if (!isEmpty()) {
            root->inOrder();
        }
        return;
    }

    bool isEmpty(){
        return (root == NULL);
    }

    ValueType search(KeyType searchedKey){
        AVLTreeNode* temp = root;
        if(root == NULL)
            return 0;
        while (true){
            if(temp->key == searchedKey){
                return temp->value;
            }
            else if(temp->right == NULL && temp->left == NULL){
                return 0;
            }
            else if(temp->key < searchedKey){
                if(temp->right == NULL)
                    return 0;
                temp = temp->right;
            }
            else if(temp->key > searchedKey){
                if(temp->left == NULL)
                    return 0;
                temp = temp->left;
            }
        }
    }

    std::string toString() const{
        std::stringstream localStream;
        if (root != NULL)
            localStream<<root->toString();

        return localStream.str();
    }
};
