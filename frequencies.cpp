// freqencies.cpp

#include "map.h"
#include <strings.h>
#include <unistd.h>

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
                if(strcasecmp(optarg, "key")==0){
                        df = DUMP_KEY;
                }
                else if(strcasecmp(optarg, "value")==0){
                        df = DUMP_VALUE;
                }
                else if(strcasecmp(optarg, "key_value")==0){
                        df = DUMP_KEY_VALUE;
                }
                else if(strcasecmp(optarg, "value_key")==0){
                        df = DUMP_VALUE_KEY;
                }
                else{ usage(1); }
            default:
                usage(1);
                break;
        }
    }
    if(map==nullptr){
        map = new UnsortedMap();
    }
}

std::string increment(const std::string &s){
    int intVal = std::stoi(s);
    intVal++;
    return std::to_string(intVal);
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    DumpFlag df = DUMP_VALUE_KEY;
    Map *map = nullptr;
    parse_options(argc, argv, map, df);

    std::string word;
    while(std::cin >> word){
        if(map->search(word) == NONE){
            map->insert(word, "1");
        }
        else{
            //update value
            map->insert(word, increment( (map->search(word)).second ));
        }
    }

    map->dump(std::cout, df);

    return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
