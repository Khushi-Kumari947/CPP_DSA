#include <iostream>
#include <queue> 
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;  // Pointer to the parent node

    Node(int value) {
        key = value;
        left = right = parent = nullptr;
    }
};

class MaxHeap {
private:
    Node* root;

    void heapifyUp(Node* node) {
        if (node == nullptr || node->parent == nullptr) {
            return;
        }
        if (node->key > node->parent->key) {
            swap(node->key, node->parent->key);
            heapifyUp(node->parent);
        }
    }

    void heapifyDown(Node* node) {
        if (node == nullptr) {
            return;
        }

        Node* largest = node;

        if (node->left != nullptr && node->left->key > largest->key) {
            largest = node->left;
        }

        if (node->right != nullptr && node->right->key > largest->key) {
            largest = node->right;
        }

        if (largest != node) {
            swap(node->key, largest->key);
            heapifyDown(largest);
        }
    }

    Node* insert(Node* node, int key, Node* parent = nullptr) {
        if (node == nullptr) {
            Node* newNode = new Node(key);
            newNode->parent = parent;  // Set parent
            return newNode;
        }

        if (key <= node->key) {
            if (node->left == nullptr) {
                node->left = insert(node->left, key, node);
            } else if (node->right == nullptr) {
                node->right = insert(node->right, key, node);
            } else {
                // Insert into the subtree which has space
                if (height(node->left) <= height(node->right)) {
                    node->left = insert(node->left, key, node);
                } else {
                    node->right = insert(node->right, key, node);
                }
            }
        }

        heapifyUp(node);
        return node;
    }

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }

public:
    MaxHeap() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteMax() {
        if (root == nullptr) {
            cout << "Heap is empty!" << endl;
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } else if (root->right != nullptr && root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else {
            // Find the last node in level order
            Node* lastNode = findLastNode(root);
            root->key = lastNode->key;
            delete lastNode;
            heapifyDown(root);
        }
    }

    void printHeap(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->key << " ";
        printHeap(node->left);
        printHeap(node->right);
    }

    Node* getRoot() {
        return root;
    }

    Node* findLastNode(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->left == nullptr && node->right == nullptr) {
            return node;
        }

        if (height(node->left) > height(node->right)) {
            return findLastNode(node->left);
        } else {
            return findLastNode(node->right);
        }
    }

    // Function to perform level order traversal
    void levelOrderTraversal() {
        if (root == nullptr) {
            cout << "Heap is empty!" << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->key << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
};


int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(6);
    heap.insert(1);
    heap.insert(8);

    cout << "Heap elements in level order: ";
    heap.levelOrderTraversal();
    cout << endl;

    heap.deleteMax();
    cout << "Heap after deleting max element in level order: ";
    heap.levelOrderTraversal();
    cout << endl;

    return 0;
}
