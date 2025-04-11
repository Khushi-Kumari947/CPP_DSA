#include <iostream>
using namespace std;

// Define the TreeNode class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Define the BST class
class BST {
public:
    TreeNode* root;

    BST() : root(NULL) {}

    // Function to insert a new node into the BST
    void insert(int key) {
        root = insertRec(root, key);
    }

    // Function to find the height of the BST
    int findHeight() {
        return findHeightRec(root);
    }

private:
    // Recursive helper function for inserting a new node
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == NULL) {
            return new TreeNode(key);
        }
        if (key < node->val) {
            node->left = insertRec(node->left, key);
        } else {
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    // Recursive helper function to calculate the height of the BST
    int findHeightRec(TreeNode* node) {
        if (node == NULL) {
            return -1;  // Return -1 for an empty tree (no edges)
        }
        int leftHeight = findHeightRec(node->left);
        int rightHeight = findHeightRec(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

// Example usage
int main() {
    BST tree;
    int inputs[] = {3, 1, 5, 0, 2, 4, 6};  // Example input series
    int n = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < n; ++i) {
        tree.insert(inputs[i]);
    }

    cout << "The height of the BST is: " << tree.findHeight() << endl;

    return 0;
}
