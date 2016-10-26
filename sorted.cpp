// sorted.cpp: Sorted Map

#include "map.h"
#include <iterator>
#include <cmath>
#include <algorithm>

// Type Definitions ------------------------------------------------------------

typedef std::vector<Entry>::iterator IT;

// Prototypes ------------------------------------------------------------------

const Entry     binary_search(const IT &start, const IT &end, const std::string &key);

// Methods ---------------------------------------------------------------------

void            SortedMap::insert(const std::string &key, const std::string &value) {
    for(IT it=entries.begin(); it!=entries.end(); ++it){
        if(key >= it->first){
            entries.insert(it, make_pair(key, value));
        }
    }
}

const Entry     SortedMap::search(const std::string &key) {
    return NONE;
}

void            SortedMap::dump(std::ostream &os, DumpFlag flag) {
}

// Internal Functions ----------------------------------------------------------

bool compareKey(const Entry &one, const Entry &two){
    return one.first <= two.first;
}

const Entry   binary_search(const IT &start, const IT &end, const std::string &target) {
    IT low = lower_bound(start, end, Entry(target, 0), compareKey);
    if( low->first == target){
        return *low;
    }
    else{
        return NONE;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
