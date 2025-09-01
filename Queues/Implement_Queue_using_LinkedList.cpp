#include <iostream>
using namespace std;

class QueueNode {
public:
    int data;
    QueueNode *next;
    QueueNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyQueue {
public:
    QueueNode *front;
    QueueNode *rear;
    MyQueue() { front = rear = NULL; }

    void push(int x);
    int pop();
    int peek();      // get front element
    bool empty();    // check if queue is empty
};

// Function to push an element into the queue.
void MyQueue::push(int x) {
    QueueNode *nn = new QueueNode(x);
    if (rear == NULL) {
        front = rear = nn;
        return;
    }
    rear->next = nn;
    rear = nn;
}

// Function to pop front element from the queue.
int MyQueue::pop() {
    if (front == NULL)
        return -1;
    int d = front->data;
    QueueNode *temp = front;

    if (front == rear) { // only one element
        front = rear = NULL;
    } else {
        front = front->next;
    }

    delete temp;
    return d;
}

// Function to get front element without removing
int MyQueue::peek() {
    if (front == NULL)
        return -1; // queue empty
    return front->data;
}

// Function to check if queue is empty
bool MyQueue::empty() {
    return (front == NULL);
}

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Peek: " << q.peek() << endl;   // 10
    cout << "Popped: " << q.pop() << endl;  // 10

    cout << "Peek: " << q.peek() << endl;   // 20
    cout << "Popped: " << q.pop() << endl;  // 20

    cout << "Peek: " << q.peek() << endl;   // 30
    cout << "Popped: " << q.pop() << endl;  // 30

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
