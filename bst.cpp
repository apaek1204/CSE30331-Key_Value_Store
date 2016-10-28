// bst.cpp: BST Map

#include "map.h"

#include <stdexcept>

// Prototypes ------------------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value);
Node *search_r(Node *node, const std::string &key);
void    dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------
BSTMap::BSTMap(){
    root = nullptr;
}
BSTMap::~BSTMap(){
    erase(root);
}
void BSTMap::erase(Node * curr){
    if(!curr){
        return;
    }
    erase(curr->left);
    erase(curr->right);
    delete curr;
}
void BSTMap::insert(const std::string &key, const std::string &value) {
    root = insert_r(root, key, value);
}

const Entry BSTMap::search(const std::string &key) {
    Node *a = search_r(root, key);
    
    if(a){
        return a->entry;
    }
    else{
        return NONE;
    }
}

void BSTMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root,os,flag);
}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    if(node == nullptr){
        node = new Node{ Entry(key, value), 0, nullptr, nullptr }; 
        return node;
    }
    else{
        if(key > (node->entry).first){
            node->right = insert_r(node->right, key, value);
            
        }
        else if(key == node->entry.first){
            node->entry.second = value;
        }
        else{
            node->left = insert_r(node->left, key, value);
        }
    }
    return node;
}

Node *search_r(Node *node, const std::string &key) {
    if(node){
        if((node->entry).first == key){
            return node;
        }
        else if((node->entry).first < key){
            node = search_r(node->right,key);
        }
        else{
            node = search_r(node->left,key);
        }
    }
    else{
        return nullptr;
    }
    return node;
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) {
    switch (flag){
        case DUMP_KEY:
            if(node == nullptr){
                return;
            }
            else{
                dump_r(node->left, os, flag);
                os << node->entry.first << "\t\t";
                dump_r(node->right, os, flag);
                os << node->entry.first << "\t\t";   
            }
            break;
        case DUMP_VALUE:
            if(node == nullptr){
                return;
            }
            else{
                dump_r(node->left, os, flag);
                os << node->entry.second<< "\t\t";
                dump_r(node->right, os, flag);
                os << node->entry.second << "\t\t";   
            }
            break;
        case DUMP_KEY_VALUE:
            if(node == nullptr){
                return;
            }
            else{
                dump_r(node->left, os, flag);
                os << node->entry.first<< "\t\t" << node->entry.second<< "\t\t";
                dump_r(node->right, os, flag);
                os << node->entry.first << "\t\t" << node->entry.second << "\t\t";   
            }
            break;
        case DUMP_VALUE_KEY:
            if(node == nullptr){
                return;
            }
            else{
                dump_r(node->left, os, flag);
                os << node->entry.second<< "\t\t" << node->entry.first<< "\t\t";
                dump_r(node->right, os, flag);
                os << node->entry.second << "\t\t" << node->entry.first << "\t\t";   
            }
            break;

    }
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
