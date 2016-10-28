// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>

// Prototypes ------------------------------------------------------------------

static Node *insert_r(Node *node, const std::string &key, const std::string &value);
extern Node *search_r(Node *node, const std::string &key);
extern void    dump_r(Node *node, std::ostream &os, DumpFlag flag);
static Node *rotate_right(Node *p);
static Node *rotate_left(Node *p);
static int get_random();

// Methods ---------------------------------------------------------------------

void            TreapMap::insert(const std::string &key, const std::string &value) {
    head = insert_r(head, key, value);
}

const Entry     TreapMap::search(const std::string &key) {
    return NONE;
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    if(node==nullptr){
        node = new Node{Entry(key, value), get_random(), nullptr, nullptr};
    }

    if(key <= (node->entry).first){
        node->left = insert_r(node->left, key, value);
        if(node->left->priority > node->priority){
            node = rotate_right(node);
        }
    }
    else{
        node->right = insert_r(node->right, key, value);
        if(node->right->priority > node->priority){
            node = rotate_left(node);
        }
    }

    return node;
}

Node *rotate_right(Node *p) {
    Node* left_child = p->left;
    Node* lefts_right = left_child->right;
    left_child->right = p;
    p->left = lefts_right;
    return left_child;
}

Node *rotate_left(Node *p) {
    Node* right_child = p->right;
    Node* rights_left = right_child->left;
    right_child->left = p;
    p->right = rights_left;
    return right_child;
}

int get_random() {
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<> d(1, INT_MAX);
    return d(g);
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
