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
| Sorted | O(1) | O(n) | O(n) | O(1) | O(logn) | O(logn) |
| BST | O(1) | O(logn) | O(n) | O(1) | O(logn) | O(n) |
| RBTree | O(1) | O(logn) | O(logn) | O(1) | O(logn) | O(logn) |
| Treap | O(1) | O(logn) | O(n) | O(1) | O(logn) | O(n) |



    All insert best case complexities are O(1) because the data structure could be empty before the insert, leading to only a check to see if the datastructure is empty before inserting. Similarly, all search best case complexities are O(1) because the element being searched for could be the first element.

    For unsorted and sorted, the avg/worst for insert is O(n) because you have to search through the entire data structure in case the key already exists, since that would require a change in value rather than an actual insert. For unsorted, the avg/worst for search is O(n) because you have to search element by element to find the target. For a sorted array, the avg/worst search is O(logn) because the list is ordered, allowing you to utilize binary search.

    The avg insert and search for BST is O(logn) because on average, the tree would be fairly balanced, guaranteeing logn. The worst insert and search for BST is O(n) because it could be a linked list.

    The avg and worst complexities for RBTrees are O(logn) because the tree will rebalance itself, guaranteeing a balanced tree.

    The avg insert and search for Treap is O(logn) because on average, it would be fairly balanced, gauranteeing logn. In the worst case, the Treap would be a linked list, having O(n) time complexity.


2. | Backend | NITEMS | PADLENGTH | Insert Time | Search Time |
|---|---|---|---|---|
| Unsorted | 10 | 1 | 3.9231e-05s | 8.31e-06s |
| Unsorted | 10 | 2 | 4.8206e-05s | 1.0968e-05s |
| Unsorted | 10 | 4 | 5.3942e-05s | 1.4234e-05s |
| Unsorted | 10 | 8 | 6.5617e-05s | 1.4882e-05s |
| Unsorted | 100 | 1 | 0.000414815s | 0.000324367s |
| Unsorted | 100 | 2 | 0.000429629s | 0.000337667s |
| Unsorted | 100 | 4 | 0.000510748s | 0.000367109s |
| Unsorted | 100 | 8 | 0.000597136s | 0.000415431s |
| Unsorted | 1000 | 1 | 0.0326906s | 0.0310389s |
| Unsorted | 1000 | 2 | 0.0329162s | 0.0315327s |
| Unsorted | 1000 | 4 | 0.0325051s | 0.0317742s |
| Unsorted | 1000 | 8 | 0.0333844s | 0.0308615s |
| Unsorted | 10000 | 1 | 3.27093s | 3.15092s |
| Unsorted | 10000 | 2 | 3.30336s | 3.25183s |
| Unsorted | 10000 | 4 | 3.385s | 3.30183s |
| Unsorted | 10000 | 8 | 3.45601s | 3.41887s |
| Unsorted | 100000 | 1 | 378.638s | 378.737s |
| Unsorted | 100000 | 2 | 388.408s | 366.284s |
| Unsorted | 100000 | 4 | 397.622s | 390.65s |
| Unsorted | 100000 | 8 | 379.936s | 362.321s |
| Unsorted | 1000000 | 1 | INFINITY | INFINITY |
| Unsorted | 1000000 | 2 | INFINITY | INFINITY |
| Unsorted | 1000000 | 4 | INFINITY | INFINITY |
| Unsorted | 1000000 | 8 | INFINITY | INFINITY |
| Unsorted | 10000000 | 1 | INFINITY | INFINITY |
| Unsorted | 10000000 | 2 | INFINITY | INFINITY |
| Unsorted | 10000000 | 4 | INFINITY | INFINITY |
| Unsorted | 10000000 | 8 | INFINITY | INFINITY |
| Sorted | 10 | 1 | 4.4445e-05s | 9.593e-06s |
| Sorted | 10 | 2 | 4.8597e-05s | 1.1371e-05s |
| Sorted | 10 | 4 | 5.4849e-05s | 1.4758e-05s |
| Sorted | 10 | 8 | 5.9349e-05s | 1.6813e-05s |
| Sorted | 100 | 1 | 0.000559877s | 0.000111353s |
| Sorted | 100 | 2 | 0.000551408s | 0.000116298s |
| Sorted | 100 | 4 | 0.000660137s | 0.000158284s |
| Sorted | 100 | 8 | 0.000677484s | 0.00019078s |
| Sorted | 1000 | 1 | 0.0426114s | 0.00167979s |
| Sorted | 1000 | 2 | 0.04285s | 0.00165369s |
| Sorted | 1000 | 4 | 0.0421532s | 0.00185745s |
| Sorted | 1000 | 8 | 0.0455344s | 0.0021104s |
| Sorted | 10000 | 1 | 4.25152s | 0.0192874s |
| Sorted | 10000 | 2 | 4.25819s | 0.0224103s |
| Sorted | 10000 | 4 | 4.67961s | 0.0189596s |
| Sorted | 10000 | 8 | 4.58075s | 0.0237571s |
| Sorted | 100000 | 1 | 593.91s | 0.243498s |
| Sorted | 100000 | 2 | 531.57s | 0.243214s |
| Sorted | 100000 | 4 | 526.483s | 0.254201s |
| Sorted | 100000 | 8 | 567.053s | 0.278111s |
| Sorted | 1000000 | 1 | INFINITY | INFINITY |
| Sorted | 1000000 | 2 | INFINITY | INFINITY |
| Sorted | 1000000 | 4 | INFINITY | INFINITY |
| Sorted | 1000000 | 8 | INFINITY | INFINITY |
| Sorted | 10000000 | 1 | INFINITY | INFINITY |
| Sorted | 10000000 | 2 | INFINITY | INFINITY |
| Sorted | 10000000 | 4 | INFINITY | INFINITY |
| Sorted | 10000000 | 8 | INFINITY | INFINITY |
| BST | 10 | 1 | 3.1224e-05s | 9.217e-06s |
| BST | 10 | 2 | 3.8526e-05s | 1.2762e-05s |
| BST | 10 | 4 | 4.7278e-05s | 1.513e-05s |
| BST | 10 | 8 | 4.4312e-05s | 1.585e-05s |
| BST | 100 | 1 | 0.000123606s | 8.6433e-05s |
| BST | 100 | 2 | 0.000322625s | 0.000293732s |
| BST | 100 | 4 | 0.000323624s | 0.000329189s |
| BST | 100 | 8 | 0.000424302s | 0.000367087s |
| BST | 1000 | 1 | 0.00134421s | 0.00108358s |
| BST | 1000 | 2 | 0.0027506s | 0.00259543s |
| BST | 1000 | 4 | 0.0210101s | 0.0277621s |
| BST | 1000 | 8 | 0.0217532s | 0.0300351s |
| BST | 10000 | 1 | 0.0150356s | 0.0133779s |
| BST | 10000 | 2 | 0.0295236s | 0.0295158s |
| BST | 10000 | 4 | 2.36488s | 3.50336s |
| BST | 10000 | 8 | 2.95281s | 3.70552s |
| BST | 100000 | 1 | 0.178045s | 0.161732s |
| BST | 100000 | 2 | 0.319564s | 0.327963s |
| BST | 100000 | 4 | 26.0824s | 26.891s |
| BST | 100000 | 4 | INFINITY | INFINITY |
| BST | 1000000 | 1 | 1.99464s | 1.92173s |
| BST | 1000000 | 2 | 3.4978s | 3.48801s |
| BST | 1000000 | 4 | 269.385s | 260.132s |
| BST | 1000000 | 8 | INFINITY | INFINITY |
| BST | 10000000 | 1 | 1.99464s | 1.92173s |
| BST | 10000000 | 2 | 36.7909s | 39.3248s |
| BST | 10000000 | 4 | INFINITY | INFINITY |
| BST | 10000000 | 8 | INFINITY | INFINITY |
| RBTree | 10 | 1 | 4.4267e-05s | 1.0268e-05s |
| RBTree | 10 | 2 | 4.8308e-05s | 1.3354e-05s |
| RBTree | 10 | 4 | 6.2945e-05s | 1.6175e-05s |
| RBTree | 10 | 8 | 5.6773e-05s | 1.8602e-05s |
| RBTree | 100 | 1 | 0.000193952s | 0.000127168s |
| RBTree | 100 | 2 | 0.000201345s | 0.000131936s |
| RBTree | 100 | 4 | 0.000259578s | 0.000160475s |
| RBTree | 100 | 8 | 0.000356982s | 0.000199542s |
| RBTree | 1000 | 1 | 0.0020946s | 0.00168083s |
| RBTree | 1000 | 2 | 0.00219629s | 0.0016675s |
| RBTree | 1000 | 4 | 0.00246251s | 0.00177904s |
| RBTree | 1000 | 8 | 0.00339341s | 0.00216877s |
| RBTree | 10000 | 1 | 0.023266s | 0.0199343s |
| RBTree | 10000 | 2 | 0.024385s | 0.0202765s |
| RBTree | 10000 | 4 | 0.0244517s | 0.0204578s |
| RBTree | 10000 | 8 | 0.0332893s | 0.0260124s |
| RBTree | 100000 | 1 | 0.273299s | 0.273449s |
| RBTree | 100000 | 2 | 0.271034s | 0.267109s |
| RBTree | 100000 | 4 | 0.26007s | 0.27484s |
| RBTree | 100000 | 8 | 0.350094s | 0.299452s |
| RBTree | 1000000 | 1 | 2.93826s | 2.98423s |
| RBTree | 1000000 | 2 | 2.93635s | 2.87588s |
| RBTree | 1000000 | 4 | 3.07775s | 2.84291s |
| RBTree | 1000000 | 8 | 3.65719s | 3.10167s |
| RBTree | 10000000 | 1 | 33.2068s | 33.3735s |
| RBTree | 10000000 | 2 | 31.7791s | 32.7271s |
| RBTree | 10000000 | 4 | 31.9825s | 33.1672s |
| RBTree | 10000000 | 8 | 41.9824s | 34.9123s |
| Treap | 10 | 1 | 0.000146489s | 6.973e-06s |
| Treap | 10 | 2 | 0.000145258s | 1.0546e-05s |
| Treap | 10 | 4 | 0.000141751s | 1.2186e-05s |
| Treap | 10 | 8 | 0.000140514s | 1.3271e-05s |
| Treap | 100 | 1 | 0.000887572s | 8.528e-05s |
| Treap | 100 | 2 | 0.000878509s | 9.4781e-05s |
| Treap | 100 | 4 | 0.000974322s | 0.000121918s |
| Treap | 100 | 8 | 0.00108579s | 0.000152472s |
| Treap | 1000 | 1 | 0.00880369s | 0.00120863s |
| Treap | 1000 | 2 | 0.00866003s | 0.00102419s |
| Treap | 1000 | 4 | 0.00962782s | 0.00142229s |
| Treap | 1000 | 8 | 0.0096452s | 0.00168119s |
| Treap | 10000 | 1 | 0.091841s | 0.0131463s |
| Treap | 10000 | 2 | 0.0915949s | 0.01328s |
| Treap | 10000 | 4 | 0.0873381s | 0.0142405s |
| Treap | 10000 | 8 | 0.098022s | 0.018523s |
| Treap | 100000 | 1 | 0.904683s | 0.186141s |
| Treap | 100000 | 2 | 0.895827s | 0.179479s |
| Treap | 100000 | 4 | 0.905343s | 0.184585s |
| Treap | 100000 | 8 | 0.985622s | 0.220107s |
| Treap | 1000000 | 1 | 9.53093s | 2.1881s |
| Treap | 1000000 | 2 | 9.3417s | 2.02173s |
| Treap | 1000000 | 4 | 9.57809s | 2.03564s |
| Treap | 1000000 | 8 | 9.5959s | 2.41457s |
| Treap | 10000000 | 1 | 96.6544s | 24.0995s |
| Treap | 10000000 | 2 | 97.4375s | 24.7046s |
| Treap | 10000000 | 4 | 99.3328s | 25.1334s |
| Treap | 10000000 | 8 | 97.0902s | 26.24s |


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



4. At smaller data sizes, unsorted and sorted were the fastest in terms of insterting and searching. Unsorted had the faster insert, but sorted had a significnatly faster search. However, as the number of elements was increasing, the total cost in time was increasing by almost 100x for 10x more elements. This shows that at larger data sizes, (un)sorted lists are extremely inefficient, as they have O(n) time complexity. However, for BSTs, Treaps and RBTrees, insert and search for large data sizes was extremely fast represented by their O(logn) average time complexity. They were decently fast at smaller data sizes, but still took more time because of their complex nature.

    As NITEMS increased, time taken to insert and search obviously increased. PADLENGTH on average also slightly, but almost negligibly, increased the time taken for all backends except BSTs, which increased exponentially. This happened because as more padding was added, BSTs became more unbalanced, eventually becoming a linked list. File size obviously also increased time taken, because there were more strings (NITEMS) to compare as file size increased.

    The RBTree is the best backend map. Although complex and somewhat more difficult to implement, it provided the lowest amount of time for large data sizes, and reasonably low times for smaller data sizes, regardless of the input because it balanced itself. Even compared to a treap, which balances itself, the RBTree was almost 3x faster.

Andrew Paek did the BST implementation and the questions, creating shell scripts to determine the time taken for increasing elements.

Emily Park did the implementations of the unsorted, sorted, RBTree, and Treap. In addition, Emily constructed the map_bench and frequencies scripts.

