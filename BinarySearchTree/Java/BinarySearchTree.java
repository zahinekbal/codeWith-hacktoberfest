/******************************************************************************
 * Binary Search Tree (Java) Output:
 * 
 *              92
 * 
 *          80
 * 
 *      70
 * 
 *          60
 * 
 * 50
 * 
 *          40
 * 
 *                  30
 * 
 *              20
 * 
 *      10
 * 
 * 50 10 40 20 30 70 60 80 
 * 10 20 30 40 50 60 70 80 
 * 30 20 40 10 60 80 70 50 
 *******************************************************************************/

// Typical Node that has key and
// left and right pointers of the key
class Node {
    int key;
    Node left, right;

    public Node(int item) {
        key = item;
        left = right = null;
    }
}

class BinarySearchTree {
    // Root node on which operations will be performed
    static Node root;
    // Space count for printing the tree
    static final int COUNT = 10;

    // Constructor - Initialize root node to null
    BinarySearchTree() {
        root = null;
    }

    // Function that will take root and key and insert it into the BST
    Node insertNode(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }

        if (key < root.key)
            root.left = insertNode(root.left, key);
        else if (key > root.key)
            root.right = insertNode(root.right, key);

        return root;
    }

    // Function that will take root and key and delete it from the BST
    Node deleteNode(Node root, int key) {
        if (root == null)
            return root;

        if (key < root.key)
            root.left = deleteNode(root.left, key);
        else if (key > root.key)
            root.right = deleteNode(root.right, key);

        else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            root.key = minValue(root.right);
            root.right = deleteNode(root.right, root.key);
        }

        return root;
    }

    // Function that will take root and spaces and prints the BST from left to right
    void print2DBST(Node root, int space) {
        if (root == null)
            return;

        space += COUNT;

        print2DBST(root.right, space);

        System.out.println();
        for (int i = COUNT; i < space; i++)
            System.out.print(" ");
        System.out.println(root.key);

        print2DBST(root.left, space);
    }

    // Function that will take root and prints the minValue from the BST
    int minValue(Node root) {
        int minv = root.key;
        while (root.left != null) {
            minv = root.left.key;
            root = root.left;
        }
        return minv;
    }

    // Function that will take root and prints the preorder traversal of the BST
    void preorderTraversal(Node root) {
        if (root != null) {
            System.out.print(root.key + " ");
            preorderTraversal(root.left);
            preorderTraversal(root.right);
        }
    }

    // Function that will take root and prints the inorder traversal of the BST
    void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print(root.key + " ");
            inorderTraversal(root.right);
        }
    }

    // Function that will take root and prints the postorder traversal of the BST
    void postorderTraversal(Node root) {
        if (root != null) {
            postorderTraversal(root.left);
            postorderTraversal(root.right);
            System.out.print(root.key + " ");
        }
    }

    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();

        tree.root = tree.insertNode(tree.root, 50);
        tree.root = tree.insertNode(tree.root, 10);
        tree.root = tree.insertNode(tree.root, 70);
        tree.root = tree.insertNode(tree.root, 40);
        tree.root = tree.insertNode(tree.root, 80);
        tree.root = tree.insertNode(tree.root, 92);
        tree.root = tree.insertNode(tree.root, 60);
        tree.root = tree.insertNode(tree.root, 20);
        tree.root = tree.insertNode(tree.root, 30);

        tree.print2DBST(tree.root, 0);
        System.out.println();

        tree.root = tree.deleteNode(tree.root, 92);

        tree.preorderTraversal(tree.root);
        System.out.println();

        tree.inorderTraversal(tree.root);
        System.out.println();

        tree.postorderTraversal(tree.root);
        System.out.println();
    }
}
