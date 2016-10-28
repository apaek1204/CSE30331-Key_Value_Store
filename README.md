Project 03 - Key-Value Store I
==============================

This [project] implements a variety of [map] backends for a basic [key-value
store].

[project]:          https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project03.html
[map]:              https://en.wikipedia.org/wiki/Associative_array
[key-value store]:  https://en.wikipedia.org/wiki/Key-value_database



1. |Backend|Insert|---|---|Search|---|---|
|---|Best|Avg|Worst|Best|Avg|Worst|
|---|---|---|---|---|---|---|
|Unsorted|O(1)|O(n)|O(n)|O(1)|O(n)|O(n)|
|Sorted|O(1)|O(n)|O(n)|O(1)|O(n)|O(n)|
|BST|O(1)|O(logn)|O(n)|O(1)|O(logn)|O(n)|
|RBTree|O(1)|O(logn)|O(logn)|O(1)|O(logn)|O(logn)|
|Treap|O(1)|O(logn)|O(n)|O(1)|O(logn)|O(n)|



    All insert best case complexities are O(1) because the data structure could be empty before the insert, leading to only a check to see if the datastructure is empty before inserting. Similarly, all search best case complexities are O(1) because the element being searched for could be the first element.

    For unsorted and sorted, the avg/worst for insert is O(n) because you have to search through the entire data structure in case the key already exists, since that would require a change in value rather than an actual insert. Similarly, their avg/worst search is O(n) because _.
    
    The avg insert and search for BST is O(logn) because on average, the tree would be fairly balanced, guaranteeing logn. The worst insert and search for BST is O(n) because it could be a linked list in the worst case scenario.

    The avg and worst complexities for RBTrees are O(logn) because the tree will rebalance itself, guaranteeing a balanced tree.

    The avg insert and search for Treap is O(logn) because on average, it would be fairly balanced, gauranteeing logn. In the worst case, the Treap would be a linked list, making O(n).


2. 


3.


4.
