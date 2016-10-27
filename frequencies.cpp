// freqencies.cpp

#include "map.h"

// Parse options
void usage(int status){
    std::cout << "usage: map_bench" << std::endl
              << "  -b BACKEND      Which Map backend (unsorted, sorted, bst, rbtree, treap)" << std::endl
              << "  -d DUMPFLAG     Which dumpflag (key, value, key_value, value_key)" << std::endl;
}

void parse_options(int argc, char *argv[], Map *&map, DumpFlag &df){
    int c;
    while ((c=getopt(argc, argv, "b:d:")) != -1){
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
            case 'd':
                switch(optarg){
                    case 'key':
                        df = DUMP_KEY;
                        break;
                    case 'value':
                        df = DUMP_VALUE;
                        break;
                    case 'key_value':
                        df = DUMP_KEY_VALUE;
                        break;
                    case 'value_key':
                        df = DUMP_VALUE_KEY;
                        break;
                }
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


// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    DumpFlag df = DUMP_VALUE_KEY;
    Map *map = nullptr;
    parse_options(argc, argv, map, df);

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
