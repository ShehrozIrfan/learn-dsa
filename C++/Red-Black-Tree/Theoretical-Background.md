**Introduction:**
When it comes to searching and sorting data, one of the most fundamental data structures is the binary search tree. However, the performance of a binary search tree is highly dependent on its shape, and in the worst case, it can degenerate into a linear structure with a time complexity of O(n). This is where Red Black Trees come in, they are a type of balanced binary search tree that use a specific set of rules to ensure that the tree is always balanced. This balance guarantees that the time complexity for operations such as insertion, deletion, and searching is always O(log n), regardless of the initial shape of the tree.

Red Black Trees are self-balancing, meaning that the tree adjusts itself automatically after each insertion or deletion operation. It uses a simple but powerful mechanism to maintain balance, by coloring each node in the tree either red or black. 


*Properties of Red Black Tree:*
The Red-Black tree satisfies all the properties of binary search tree in addition to that it satisfies following additional properties –

1. *Root property*: The root is black.

2. *External property*: Every leaf (Leaf is a NULL child of a node) is black in Red-Black tree.

3. *Internal property*: The children of a red node are black. Hence possible parent of red node is a black node.

4. *Depth property*: All the leaves have the same black depth.

5. *Path property*: Every simple path from root to descendant leaf node contains same number of black nodes.

*Why Red-Black Trees?*
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that the height of the tree remains O(log n) after every insertion and deletion, then we can guarantee an upper bound of O(log n) for all these operations. The height of a Red-Black tree is always O(log n) where n is the number of nodes in the tree. 
