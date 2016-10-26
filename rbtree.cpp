// rbtree.cpp: RBTree Map

#include "map.h"

#include <algorithm>

// Methods --------------------------------------------------------------------

void            RBTreeMap::insert(const std::string &key, const std::string &value) {
    entries[key] = value;
}

const Entry     RBTreeMap::search(const std::string &key) {
    if(entries.find(key) != entries.end() ){
        return Entry( key, entries[key] );
    }
    else{
        return NONE;
    }
}

void            RBTreeMap::dump(std::ostream &os, DumpFlag flag) {
    for(auto it = entries.begin(); it!=entries.end(); ++it){
        switch(flag){
            case(DUMP_KEY):
                os << it->first;
                break;
            case(DUMP_VALUE):
                os << it->second;
                break;
            case(DUMP_KEY_VALUE):
                os << it->first << "\t\t" << it->second;
                break;
            case(DUMP_VALUE_KEY):
                os << it->second << "\t\t" << it->first;
                break;
        }
        os << std::endl;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
