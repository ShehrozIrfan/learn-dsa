// This code defines a TreeNode class to represent the nodes of the binary search tree 
// and a BinarySearchTree class to manage the tree. It includes methods for insertion (insert), 
// searching (search), and in-order traversal (inOrderTraversal). The main method demonstrates 
// how to create a BST, insert elements, perform in-order traversal, and search for specific 
// values in the tree.


class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    public TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BinarySearchTree {
    private TreeNode root;

    public BinarySearchTree() {
        root = null;
    }

    public void insert(int value) {
        root = insertRec(root, value);
    }

    private TreeNode insertRec(TreeNode root, int value) {
        if (root == null) {
            root = new TreeNode(value);
            return root;
        }

        if (value < root.data) {
            root.left = insertRec(root.left, value);
        } else if (value > root.data) {
            root.right = insertRec(root.right, value);
        }

        return root;
    }

    public boolean search(int value) {
        return searchRec(root, value);
    }

    private boolean searchRec(TreeNode root, int value) {
        if (root == null) {
            return false;
        }

        if (root.data == value) {
            return true;
        }

        if (value < root.data) {
            return searchRec(root.left, value);
        }

        return searchRec(root.right, value);
    }

    public void inOrderTraversal() {
        inOrderTraversal(root);
    }

    private void inOrderTraversal(TreeNode root) {
        if (root != null) {
            inOrderTraversal(root.left);
            System.out.print(root.data + " ");
            inOrderTraversal(root.right);
        }
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();

        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);

        System.out.println("In-order traversal of the BST:");
        bst.inOrderTraversal();

        int searchValue = 40;
        System.out.println("\nSearch for " + searchValue + ": " + bst.search(searchValue));

        searchValue = 90;
        System.out.println("Search for " + searchValue + ": " + bst.search(searchValue));
    }
}
