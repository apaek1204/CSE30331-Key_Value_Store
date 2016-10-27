// sorted.cpp: Sorted Map

#include "map.h"
#include <iterator>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>

// Type Definitions ------------------------------------------------------------

typedef std::vector<Entry>::iterator IT;

// Prototypes ------------------------------------------------------------------

const Entry     binary_search(const IT &start, const IT &end, const std::string &key);

// Methods ---------------------------------------------------------------------

void            SortedMap::insert(const std::string &key, const std::string &value) {
    if(entries.empty()){
        entries.push_back(Entry(key, value));
        return;
    }
    for(IT it=entries.begin(); it!=entries.end() ; ++it){
        //if key exists, update value
        if(it->first == key){
            it->second = value;
            return;
        }
    }

    IT test = entries.end()-1;
    for(auto t=entries.rbegin(); t!=entries.rend(); ++t){
        test--;
        if(key < t->first){
            entries.insert(++test, Entry(key, value));
        }
    }

}

const Entry     SortedMap::search(const std::string &key) {
    for(auto it=entries.begin(); it!=entries.end(); ++it){
    }
    std::cout<<std::endl;
    return binary_search(entries.begin(), entries.end(), key);
}

void            SortedMap::dump(std::ostream &os, DumpFlag flag) {
    for(auto it=entries.begin(); it!=entries.end(); ++it){
        switch(flag){
            case DUMP_KEY:
                os << it->first;
                break;
            case DUMP_VALUE:
                os << it->second;
                break;
            case DUMP_KEY_VALUE:
                os << it->first << "\t\t" << it->second;
                break;
            case DUMP_VALUE_KEY:
                os << it->second << "\t\t" << it->first;
                break;
        }
        os << std::endl;
    }
}

// Internal Functions ----------------------------------------------------------

const Entry   binary_search(const IT &start, const IT &end, const std::string &target) {
    //copy consts
    IT Start = start;
    IT End = end;
    while(Start < End){
        auto length = End - Start;
        auto Middle = length/2;
        auto midpoint = *(Start+Middle);
        if(target < midpoint.first){ End = Start + Middle; }
        else if(target > midpoint.first){ Start = Start+Middle+1; }
        else{ return midpoint; }
    }
    return NONE;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
