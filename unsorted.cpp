// unsorted.cpp: Unsorted Map

#include "map.h"

// Methods --------------------------------------------------------------------

void            UnsortedMap::insert(const std::string &key, const std::string &value) {
    entries.push_back(make_pair(key, value));
}

const Entry     UnsortedMap::search(const std::string &key) {
    for(auto it = entries.begin(); it!=entries.end(); ++it){
        if(it->first == key){
            return *it;
        }
    }
    return NONE;
}

void            UnsortedMap::dump(std::ostream &os, DumpFlag flag) {
    for(auto it = entries.begin(); it!=entries.end(); ++it){
        if(flag == DUMP_KEY || flag == DUMP_KEY_VALUE){
            os << it->first;
        }
        if(flag == DUMP_VALUE || flag == DUMP_KEY_VALUE || flag == DUMP_VALUE_KEY){
            os << "     " << it->second;
        }
        if(flag == DUMP_VALUE_KEY){
            os << "     " << it->first;
        }
        os << std::endl;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
