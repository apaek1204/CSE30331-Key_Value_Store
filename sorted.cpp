// sorted.cpp: Sorted Map

#include "map.h"

#include <algorithm>

// Type Definitions ------------------------------------------------------------

typedef std::vector<Entry>::iterator IT;

// Prototypes ------------------------------------------------------------------

const Entry     binary_search(const IT &start, const IT &end, const std::string &key);

// Methods ---------------------------------------------------------------------

void            SortedMap::insert(const std::string &key, const std::string &value) {
}

const Entry     SortedMap::search(const std::string &key) {
    return NONE;
}

void            SortedMap::dump(std::ostream &os, DumpFlag flag) {
}

// Internal Functions ----------------------------------------------------------

const Entry   binary_search(const IT &start, const IT &end, const std::string &target) {
    return NONE;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
