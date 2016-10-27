// map_bench.cpp

#include "map.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <strings.h>

void usage(int status){
    std::cout << "usage: map_bench" << std::endl
              << "  -b BACKEND      Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl
              << "  -n NITEMS       Number of items to insert and search" << std::endl
              << "  -p PADLENGTH    Amount of padding to apply to integer key and value" << std::endl;
}

void parse_options(int argc, char *argv[], Map *&map, int &nItems, int &padLength){
    int c;
    while ((c=getopt(argc, argv, "b:n:p:")) != -1){
        switch (c){
            case 'b':
                if(strcasecmp(optarg, "unsorted") == 0){
                    map = new UnsortedMap();
                }
                else if(strcasecmp(optarg, "sorted") == 0){
                    map = new SortedMap();
                }
                else if(strcasecmp(optarg, "bst") == 0){
                    map = new BSTMap();
                }
                else if(strcasecmp(optarg, "rbtree") == 0){
                    map = new RBTreeMap();
                }
                else if(strcasecmp(optarg, "treap") == 0){
                    map = new TreapMap();
                }
                else{
                    usage(1);
                }
                break;
            case 'n':
                nItems = std::stoi(optarg);
                break;
            case 'p':
                padLength = std::stoi(optarg);
                break;
            default:
                usage(1);
                break;
        }
    }
    if(map==nullptr){
        map = new UnsortedMap();
    }
}

std::string int_to_key(int i, size_t padlength){
    std::string temp = std::to_string(i);
    std::string pad="";
    for(size_t j=0; j<(padlength-temp.length()); j++){
        pad+="0";
    }
    return pad+temp;
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    Map *map = nullptr;
    int NITEMS=1, PADLENGTH=1;  //default values
    parse_options(argc, argv, map, NITEMS, PADLENGTH);

    //timestamp before insertion

    //insertion

    //timestamp after insertion

    //timestamp before search

    //search

    //timestamp after search

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
