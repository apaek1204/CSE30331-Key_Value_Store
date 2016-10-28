#!/bin/sh

PROGLIST='Unsorted Sorted BST RBTree Treap'
TIMEI=0
TIMES=0
TIME=0
echo "| Backend | NITEMS | PADLENGTH | Insert Time | Search Time |"
echo "|---|---|---|---|---|"

for programs in $PROGLIST
do
    i=10
    while [ $i -lt 10000001 ]; do
        p=1
        while [ $p -lt 9 ]; do
            if [ 
            ./map_bench -b $programs -n $i -p $p >> data.txt
            TIMEI=$(cat data.txt | cut -d" " -f2 | head -n 1)
            TIMES=$(cat data.txt | cut -d" " -f2 | tail -n 1)
            echo "| $programs | $i | $p | $TIMEI | $TIMES |"
            p=$(expr $p \* 2)
        done
        i=$(expr $i \* 10)
    done
done


