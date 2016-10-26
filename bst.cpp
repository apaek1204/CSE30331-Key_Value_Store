// bst.cpp: BST Map

#include "map.h"

#include <stdexcept>

// Prototypes ------------------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value);
Node *search_r(Node *node, const std::string &key);
void    dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------

void            BSTMap::insert(const std::string &key, const std::string &value) {
    
}

const Entry     BSTMap::search(const std::string &key) {
    return NONE;
}

void            BSTMap::dump(std::ostream &os, DumpFlag flag) {
}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    if(node == nullptr){
        node = new Node{ Entry(key, value), 0, nullptr, nullptr };
    }
    return node;
}

Node *search_r(Node *node, const std::string &key) {
    return nullptr;
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) {
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
