#include <iostream>
using namespace std;

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue() { front = 0; rear = 0; }
    void push(int);
    int pop();
};

void MyQueue ::push(int x) {
    arr[rear++] = x;
}

int MyQueue ::pop() {
    if (front == rear)
        return -1;  // Queue empty
    return arr[front++];
}

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Popped: " << q.pop() << endl; // 10
    cout << "Popped: " << q.pop() << endl; // 20

    q.push(40);
    q.push(50);

    cout << "Popped: " << q.pop() << endl; // 30
    cout << "Popped: " << q.pop() << endl; // 40
    cout << "Popped: " << q.pop() << endl; // 50
    cout << "Popped: " << q.pop() << endl; // -1 (empty)

    return 0;
}
