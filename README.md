Project 03 - Key-Value Store I
==============================

This [project] implements a variety of [map] backends for a basic [key-value
store].

[project]:          https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project03.html
[map]:              https://en.wikipedia.org/wiki/Associative_array
[key-value store]:  https://en.wikipedia.org/wiki/Key-value_database


By Andrew Paek (apaek1) and Emily Park (epark3)


1. | Backend | Insert | --- | --- | Search | ---| --- |
|---|---|---|---|---|---|---|
| --- | Best | Avg | Worst | Best | Avg | Worst |
| Unsorted | O(1) | O(n) | O(n) | O(1) | O(n) | O(n) |
| Sorted | O(1) | O(n) | O(n) | O(1) | O(n) | O(n) |
| BST | O(1) | O(logn) | O(n) | O(1) | O(logn) | O(n) |
| RBTree | O(1) | O(logn) | O(logn) | O(1) | O(logn) | O(logn) |
| Treap | O(1) | O(logn) | O(n) | O(1) | O(logn) | O(n) |



    All insert best case complexities are O(1) because the data structure could be empty before the insert, leading to only a check to see if the datastructure is empty before inserting. Similarly, all search best case complexities are O(1) because the element being searched for could be the first element.

    For unsorted and sorted, the avg/worst for insert is O(n) because you have to search through the entire data structure in case the key already exists, since that would require a change in value rather than an actual insert. Similarly, their avg/worst search is O(n) because _.
    
    The avg insert and search for BST is O(logn) because on average, the tree would be fairly balanced, guaranteeing logn. The worst insert and search for BST is O(n) because it could be a linked list in the worst case scenario.

    The avg and worst complexities for RBTrees are O(logn) because the tree will rebalance itself, guaranteeing a balanced tree.

    The avg insert and search for Treap is O(logn) because on average, it would be fairly balanced, gauranteeing logn. In the worst case, the Treap would be a linked list, making O(n).


2. d


3. | Backend | Text		| File Size | Elapsed Time |
|---|---|---|---|
| Unsorted | beowulf.txt | 295Kb | 17.57 |
| Unsorted | war.txt | 3.2Mb | 420.60 |
| Unsorted | pride.txt | 710Kb | 30.26 |
| Sorted | beowulf.txt | 295Kb | 14.92 |
| Sorted | war.txt | 3.2Mb | 956.20 |
| Sorted | pride.txt | 710Kb | 49.21 |
| BST | beowulf.txt | 295Kb | 0.16 |
| BST | war.txt | 3.2Mb | 1.94 |
| BST | pride.txt | 710Kb | 0.44 |
| RBTree | beowulf.txt | 295Kb | 0.30 |
| RBTree | war.txt | 3.2Mb | 3.56 |
| RBTree | pride.txt | 710Kb | 0.73 |
| Treap | beowulf.txt | 295Kb | 0.27 |
| Treap | war.txt | 3.2Mb | 2.92 |
| Treap | pride.txt | 710Kb | 0.60 |




4. At smaller data sizes, unsorted and sorted were the fastest in terms of insterting and searching. However, as the number of elements was increasing, the cost in time was increasing almost by 100x for 10x more elements. This shows that at larger data sizes, (un)sorted lists are extremely inefficient, as they have O(n) time complexity. However, for treaps and RBTrees, insert and search for large data sizes was extremely fast represented by their O(logn) average time complexity. They were decently fast at smaller data sizes, but still took more time because of their complex nature. BSTs 

    As NITEMS increased, time taken to insert and search obviously increased. PADLENGTH on average also slightly, but almost negligibly, increased the time taken for all backends except BSTs, which increased exponentially. File size obviously also increased time taken, because there were more strings (NITEMS) to compare as file size increased.

    The RBTree is the best backend map. Although complex and somewhat more difficult to implement, it provided the lowest amount of time for large data sizes, and reasonably low times for smaller data sizes.

Andrew Paek did the BST implementation and the questions, creating shell scripts to determine the time taken for increasing elements.

Emily Park did the implementations of the unsorted, sorted, RBTree, and Treap. In addition, Emily constructed the map_bench and frequencies scripts.

