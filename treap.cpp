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
}

const Entry     TreapMap::search(const std::string &key) {
    return NONE;
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    return node;
}

Node *rotate_right(Node *p) {
    return nullptr;
}

Node *rotate_left(Node *p) {
    return nullptr;
}

int get_random() {
    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<> d(1, INT_MAX);
    return d(g);
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
