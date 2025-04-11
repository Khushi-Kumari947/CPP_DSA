#include <iostream>
#include <queue> // Needed for level order traversal
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) {
        key = value;
        left = right = parent = nullptr;
    }
};

class MaxHeap {
private:
    Node* root;

    // Helper function to heapify up
    void heapifyUp(Node* node) {
        while (node->parent != nullptr && node->key > node->parent->key) {
            swap(node->key, node->parent->key);
            node = node->parent;
        }
    }

    // Helper function to heapify down
    void heapifyDown(Node* node) {
        while (node != nullptr) {
            Node* largest = node;

            if (node->left != nullptr && node->left->key > largest->key) {
                largest = node->left;
            }

            if (node->right != nullptr && node->right->key > largest->key) {
                largest = node->right;
            }

            if (largest != node) {
                swap(node->key, largest->key);
                node = largest;
            } else {
                break;
            }
        }
    }

    // Function to find a node with a specific value
    Node* findNode(Node* node, int value) {
        if (node == nullptr || node->key == value) {
            return node;
        }

        Node* foundNode = findNode(node->left, value);
        if (foundNode == nullptr) {
            foundNode = findNode(node->right, value);
        }
        return foundNode;
    }

    // Function to get the last node in level order
    Node* getLastNode(Node* root) {
        if (root == nullptr) return nullptr;

        queue<Node*> q;
        q.push(root);
        Node* lastNode = nullptr;

        while (!q.empty()) {
            lastNode = q.front();
            q.pop();

            if (lastNode->left != nullptr) q.push(lastNode->left);
            if (lastNode->right != nullptr) q.push(lastNode->right);
        }

        return lastNode;
    }

    // Function to delete a node in the heap
    void deleteNode(Node* node) {
        if (node == nullptr) return;

        Node* lastNode = getLastNode(root);

        if (lastNode == node) {
            if (node->parent == nullptr) { // node is the root
                root = nullptr;
            } else if (node->parent->left == node) {
                node->parent->left = nullptr;
            } else {
                node->parent->right = nullptr;
            }
            delete node;
            return;
        }

        // Swap with the last node
        swap(node->key, lastNode->key);

        // Remove last node
        if (lastNode->parent->left == lastNode) {
            lastNode->parent->left = nullptr;
        } else {
            lastNode->parent->right = nullptr;
        }
        delete lastNode;

        // Restore the heap property
        heapifyDown(node);
    }

    // Function to insert a node into the heap
    Node* insert(Node* node, int key, Node* parent = nullptr) {
        if (node == nullptr) {
            Node* newNode = new Node(key);
            newNode->parent = parent;
            return newNode;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = new Node(key);
                current->left->parent = current;
                heapifyUp(current->left);
                break;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = new Node(key);
                current->right->parent = current;
                heapifyUp(current->right);
                break;
            } else {
                q.push(current->right);
            }
        }

        return node;
    }

public:
    MaxHeap() {
        root = nullptr;
    }

    // Insert a new key into the heap
    void insert(int key) {
        if (root == nullptr) {
            root = new Node(key);
        } else {
            root = insert(root, key);
        }
    }

    // Delete a value from the heap
    void deleteValue(int value) {
        Node* nodeToDelete = findNode(root, value);
        if (nodeToDelete != nullptr) {
            deleteNode(nodeToDelete);
        } else {
            cout << "Value not found in the heap." << endl;
        }
    }

    // Level order traversal of the heap
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
        cout << endl;
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

    heap.deleteValue(5);
    cout << "Heap after deleting 5: ";
    heap.levelOrderTraversal();
    cout << endl;

    heap.deleteValue(20);
    cout << "Heap after deleting 20: ";
    heap.levelOrderTraversal();
    cout << endl;

    return 0;
}
