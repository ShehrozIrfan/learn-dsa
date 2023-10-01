__Introduction:__<br>
When it comes to searching and sorting data, one of the most fundamental data structures is the binary search tree. However, the performance of a binary search tree is highly dependent on its shape, and in the worst case, it can degenerate into a linear structure with a time complexity of O(n). This is where Red Black Trees come in, they are a type of balanced binary search tree that use a specific set of rules to ensure that the tree is always balanced. This balance guarantees that the time complexity for operations such as insertion, deletion, and searching is always O(log n), regardless of the initial shape of the tree.
<br>
Red Black Trees are self-balancing, meaning that the tree adjusts itself automatically after each insertion or deletion operation. It uses a simple but powerful mechanism to maintain balance, by coloring each node in the tree either red or black. 
<br>
Red Black Tree-
<br>
Red-Black tree is a binary search tree in which every node is colored with either red or black. It is a type of self balancing binary search tree. It has a good efficient worst case running time complexity.
<br>
Properties of Red Black Tree:
The Red-Black tree satisfies all the properties of binary search tree in addition to that it satisfies following additional properties –

1. Root property: The root is black.

2. External property: Every leaf (Leaf is a NULL child of a node) is black in Red-Black tree.
<br>
3. Internal property: The children of a red node are black. Hence possible parent of red node is a black node.
<br>
4. Depth property: All the leaves have the same black depth.
<br>
5. Path property: Every simple path from root to descendant leaf node contains same number of black nodes. 
<br>
The result of all these above-mentioned properties is that the Red-Black tree is roughly balanced.
<br>
Rules That Every Red-Black Tree Follows:<br> 
Every node has a color either red or black.<br>
The root of the tree is always black.<br>
There are no two adjacent red nodes (A red node cannot have a red parent or red child).<br>
Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes. Every leaf (e.i. NULL node) must be colored BLACK.<br>
Why Red-Black Trees?<br>
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that the height of the tree remains O(log n) after every insertion and deletion, then we can guarantee an upper bound of O(log n) for all these operations. The height of a Red-Black tree is always O(log n) where n is the number of nodes in the tree. <br>



Comparison with AVL Tree:<br>
The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. So if your application involves frequent insertions and deletions, then Red-Black trees should be preferred. And if the insertions and deletions are less frequent and search is a more frequent operation, then AVL tree should be preferred over the Red-Black Tree.<br>

How does a Red-Black Tree ensure balance?<br>
A simple example to understand balancing is, that a chain of 3 nodes is not possible in the Red-Black tree. We can try any combination of colors and see if all of them violate the Red-Black tree property. <br>

Interesting points about Red-Black Tree:<br>
The black height of the red-black tree is the number of black nodes on a path from the root node to a leaf node. Leaf nodes are also counted as black nodes. So, a red-black tree of height h has black height >= h/2.<br>
Height of a red-black tree with n nodes is h<= 2 log2(n + 1).<br>
All leaves (NIL) are black.<br>
The black depth of a node is defined as the number of black nodes from the root to that node i.e the number of black ancestors.<br>
Every red-black tree is a special case of a binary tree.<br>
Black Height of a Red-Black Tree : <br>
Black height is the number of black nodes on a path from the root to a leaf. Leaf nodes are also counted black nodes. From the above properties 3 and 4, we can derive, a Red-Black Tree of height h has black-height >= h/2. <br>
Every Red Black Tree with n nodes has height <= 2Log2(n+1) <br>
This can be proved using the following facts:<br>

For a general Binary Tree, let k be the minimum number of nodes on all root to NULL paths, then n >= 2k – 1 (Ex. If k is 3, then n is at least 7). This expression can also be written as k <= Log2(n+1).<br>
From property 4 of Red-Black trees and above claim, we can say in a Red-Black Tree with n nodes, there is a root to leaf path with at-most Log2(n+1) black nodes.<br>
From properties 3 and 5 of Red-Black trees, we can claim that the number of black nodes in a Red-Black tree is at least ⌊ n/2 ⌋ where n is the total number of nodes.<br>
From the above points, we can conclude the fact that Red Black Tree with n nodes has a height <= 2Log2(n+1)<br>
