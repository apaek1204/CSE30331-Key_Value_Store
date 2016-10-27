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

bool compar(const Entry &one, const Entry &two){
    return one.first < two.first;
}

void            SortedMap::insert(const std::string &key, const std::string &value) {
    IT it;
    for(it=entries.begin(); it!=entries.end() ; ++it){
     //   std::cout<< it->first << ", ";
        //if key exists, update value
        if(it->first == key){
            std::cout<<"updating\n";
            //std::cout << "updating " << it->second << " to " << value << std::endl;
            it->second = value;
            //std::cout<< it->first << " " << it->second <<std::endl;
            return;
        }
    }

    //IT test = entries.end()-1;

    IT test = std::lower_bound( entries.begin(), entries.end(), key, compar);
    entries.insert(test, Entry(key, value));
    
    for(auto b = entries.begin(); b!=entries.end(); ++b){
        std::cout << b->first << " ";
    }
    std::cout<<std::endl;

/*    for(IT its=(entries.end()-1); its>=entries.begin(); --its){
        std::cout<<"hey"<<std::endl;
        test--;
        if(key < its->first){
            entries.insert(its, Entry(key, value));
            for(auto blah = entries.begin(); blah!=entries.end(); ++blah){
                std::cout << blah->first << " ";
            }
            std::cout<<std::endl;
            return;
        }
        else{
        }
    }*/

 //       entries.push_back(Entry(key, value));
  //  std::cout << key << " " << std::endl;
}

const Entry     SortedMap::search(const std::string &key) {
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
