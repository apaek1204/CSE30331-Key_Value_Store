#!/bin/sh

PROGLIST='Unsorted Sorted BST RBTree Treap'
docs='beowulf.txt war.txt pride.txt'

echo "| Backend | Text		| File Size | Elapsed Time |"
echo "|---|---|---|---|"

for program in $PROGLIST
do
	for doc in $docs
	do
		(/usr/bin/time -f "%e" sh -c "cat $doc | ./frequencies -b $program >2") &> time.txt
		TIME=$(cat time.txt | tail -n 1)
		echo "| $program | $doc | | $TIME |"
	done
done
