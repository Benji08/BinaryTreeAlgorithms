#pragma once
#include <cassert>
#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>


template<typename KeyType, typename ValueType>
class BinarySearchTree
{
private:
    struct Node{
        KeyType key;
        ValueType value;
        Node* left, *right, *parent;
    };
    Node* root;

     void deleteTree(Node* node){
        if (node != NULL){
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

     void insert(KeyType const& key, ValueType const& value, Node* node){
        if(key < node->key){
            if(node->left != NULL){
                insert(key, value, node->left);
            }else{
                node->left = new Node;
                node->left->parent = node;
                node->left->key = key;
                node->left->value = value;
                node->left->left = node->left->right = NULL;
            }
        }
        else if(key > node->key){
            if(node->right != NULL){
                insert(key, value, node->right);
            }else{
                node->right = new Node;
                node->right->parent = node;
                node->right->key = key;
                node->right->value = value;
                node->right->left = node->right->right = NULL;
                }
        }
        else
            node->value = value;
    }

    size_t size(Node* node) const {
        if (node == NULL)
            return 0;
        else {
            return 1 + size(node->left) + size(node->right);
        }
    }

    Node* find(KeyType const& key, Node* node){
         if (node == NULL)
             return NULL;
         if(key == node->key)
             return node;
         if(key < node->key)
             return find(key, node->left);
         else
             return find(key, node->right);
     }

    Node* remove(KeyType const& key, Node* node){
         if (node == NULL)
             return node;
         if (key < node->key)
            node->left = remove(key, node->left);
         else if (key > node->key)
            node->right = remove(key, node->right);
         else {
            if (node->left==NULL and node->right==NULL)
                return NULL;

            else if (node->left == NULL) {
                Node* temp = findMin(node->right);
                free(node);
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = findMax(node->left);
                free(node);
                return temp;
            }

            Node* temp = findMax(node->left);
            node->key = temp->key;
            node->value = temp->value;
            node->left = remove(temp->key, node->left);
        }
        return node;
    }

    Node* findMin(Node* node) {
        if(node->left == NULL)
            return node;
        else
            return findMin(node->left);
    }

    Node* findMax(Node* node) {
        if(node->right == NULL)
            return node;
        else
            return findMax(node->right);
    }

public:
    BinarySearchTree(){
        root=NULL;
    }

    ~BinarySearchTree(){
        deleteTree(root);
    }

    size_t size() const{
         if(root == NULL)
               return 0;
         else {
             return 1 + size(root->left) + size(root->right);
         }
    }

    void insert(KeyType const& key, ValueType const& value){
        if (root==NULL){
            root = new Node;
            root->key = key;
            root->value = value;
            root->parent = root->left = root->right = NULL;}
        else
             insert(key,value, root);

    }

    ValueType* find(KeyType const& key){
         if (root == NULL){
             Node* tmp = new Node;
             tmp->value=0;
             return &tmp->value;
         }
         if(key == root->key){
             ValueType* found = &root->value;
             return found;
         }
         else{
             if(find(key, root)==NULL){
                 Node* tmp = new Node;
                 tmp->value=0;
                 return &tmp->value;
             }
             else{
                 Node* tmp = find(key, root);
                 return &tmp->value;
             }
         }
    }

    void remove(KeyType const& key){
         if (root == NULL)
             return;
         if (key == root->key)
             root=NULL;
         else
            remove(key, root);
     }


    std::string toString(Node* node) const{
        std::stringstream localStream;

        localStream<<"("<<"["<<node->key<<","<<node->value<<"],";
        if(node->left != NULL)
            localStream<<toString(node->left);
        localStream<<",";
        if(node->right !=NULL)
            localStream<<toString(node->right);
        localStream<<")"
;       return localStream.str();
     }

    std::string print(Node* node, std::string indent, std::string prefix ) const{
        std::stringstream localStream;
        if(node != NULL){
            localStream<<indent<<prefix<<"["<<node->key<<", "<<node->value<<"]"<<"\n";
            localStream<<print(node->left, indent+"    ", "L: ");
            localStream<<print(node->right, indent+"    ", "R: ");
        }
        return localStream.str();
    }

    std::string toString() const{
         std::stringstream localStream;
         if (root != NULL)
             localStream<<toString(root);

        return localStream.str();
        }

   template<typename StreamType>
   void print(StreamType& stream){
        stream<<print(root, "", "");
    }
};

template<typename KeyType, typename ValueType>
std::ostream& operator <<(std::ostream& stream, BinarySearchTree<KeyType, ValueType> &tree)
{
    tree.template print<std::ostream>(stream);
    return stream;
}
