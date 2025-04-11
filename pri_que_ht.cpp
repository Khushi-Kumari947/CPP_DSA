#include <iostream>
#include <stdexcept>
#include <vector>

// A class to represent an element with its associated priority
class Element {
public:
    int data;      // The actual data
    int priority;  // The priority associated with the data

    // Constructor to initialize an element
    Element(int d, int p) : data(d), priority(p) {}
};

// Priority Queue implemented using Min-Heap
class PriorityQueue {
private:
    std::vector<Element> heapArray;  // Vector to store heap elements

    // Function to get the index of the parent node
    int parent(int i) { return (i - 1) / 2; }

    // Function to get the index of the left child node
    int leftChild(int i) { return 2 * i + 1; }

    // Function to get the index of the right child node
    int rightChild(int i) { return 2 * i + 2; }

    // Function to move up the node at the given index to maintain heap property
    void heapifyUp(int index) {
        while (index != 0 && heapArray[parent(index)].priority > heapArray[index].priority) {
            std::swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }

    // Function to move down the node at the given index to maintain heap property
    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < heapArray.size() && heapArray[left].priority < heapArray[smallest].priority) {
            smallest = left;
        }

        if (right < heapArray.size() && heapArray[right].priority < heapArray[smallest].priority) {
            smallest = right;
        }

        if (smallest != index) {
            std::swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Enqueue function to insert a new element into the priority queue
    void enqueue(int element, int prio) {
        heapArray.push_back(Element(element, prio));
        int index = heapArray.size() - 1;
        heapifyUp(index);
    }

    // Dequeue function to remove and return the element with the highest priority
    int dequeue() {
        if (heapArray.empty()) {
            throw std::underflow_error("Priority Queue underflow");
        }

        int rootData = heapArray[0].data;
        heapArray[0] = heapArray.back();
        heapArray.pop_back();
        if (!heapArray.empty()) {
            heapifyDown(0);
        }

        return rootData;
    }

    // Peek function to get the element with the highest priority without removing it
    int peek() const {
        if (heapArray.empty()) {
            throw std::underflow_error("Priority Queue is empty");
        }
        return heapArray[0].data;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return heapArray.empty();
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10, 3);  // Enqueue data 10 with priority 3
    pq.enqueue(20, 1);  // Enqueue data 20 with priority 1
    pq.enqueue(30, 2);  // Enqueue data 30 with priority 2

    std::cout << "Highest priority element (peek): " << pq.peek() << std::endl;

    std::cout << "Dequeue highest priority element: " << pq.dequeue() << std::endl;
    std::cout << "Highest priority element (peek): " << pq.peek() << std::endl;

    pq.enqueue(40, 0);  // Enqueue data 40 with priority 0
    std::cout << "Dequeue highest priority element: " << pq.dequeue() << std::endl;

    return 0;
}