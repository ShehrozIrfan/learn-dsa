public class TreeSort {
    class Node
    {
        int key;
        Node left, right;

        public Node(int item)
        {
            key = item;
            left = right = null;
        }
    }

    //root of BST
    Node root;
    TreeSort()
    {
        root = null;
    }
    void insert(int key)
    {
        root = insertRec(root, key);
    }

    //inserting new key in BST
    Node insertRec(Node root, int key)
    {
        //returns a new node if tree is empty
        if (root == null)
        {
            root = new Node(key);
            return root;
        }

        if (key < root.key)
        {
            root.left = insertRec(root.left, key);
        }
        else if (key > root.key)
        {
            root.right = insertRec(root.right, key);
        }
        return root;
    }

    //inorder traversal of BST
    void inorderRec(Node root)
    {
        if (root != null)
        {
            inorderRec(root.left);
            System.out.print(root.key + " ");
            inorderRec(root.right);
        }
    }

    //inserting 
    
    void treeins(int arr[])
    {
        for (int i = 0; i < arr.length; i++)
        {
            insert(arr[i]);
        }
    }

    public static void main(String[] args)
    {
        TreeSort ts = new TreeSort();
        int arr[] = {23, 12, 87, 10, 11, 64};
        System.out.println("Sorted Array: ");
        ts.treeins(arr);
        ts.inorderRec(ts.root);
    }
}