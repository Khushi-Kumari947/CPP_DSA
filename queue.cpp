#include  <iostream> 
using namespace std;


// the node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// the queue
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
      
        Node* new_node = new Node(value);

 
        if (front == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
      
            rear -> next = new_node;
            rear = new_node;
        }
    }

    void display() {

        Node* current = front;
        if (current == nullptr) {
            std::cout  <<  "Queue is empty"  <<  std::endl;
            return;
        }
        cout<<"elements in queue are:";
        while (current != nullptr) {
            cout  <<  current-> data<<" ";
            current = current-> next;
        }
        cout<<endl;
        
    }

    int dequeue() {
        // Check if queue is empty
        if (front == nullptr) {
            cout  <<  "Queue is empty, cannot dequeue"  << endl;
            
            return -1; 
        } else {
           
            Node* temp = front;
            front = front-> next;
            if (front == nullptr) {
                rear = nullptr;
            }

            int dequeued_value = temp-> data;
            delete temp;
            return dequeued_value;
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue(26);
    queue.enqueue(4);
    queue.enqueue(24);

    // Display the elements in the queue    
    queue.display(); 

    int dequeued_value = queue.dequeue();
    cout  <<  "Dequeued value: "  <<  dequeued_value  <<endl;

    // Display the elements after dequeue
    queue.display(); 
    return 0;
}