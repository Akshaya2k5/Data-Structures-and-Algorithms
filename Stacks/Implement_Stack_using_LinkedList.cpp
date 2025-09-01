#include <iostream>
using namespace std;

// Node structure for stack
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int x) : data(x), next(NULL) {}
};

class MyStack {
private:
    StackNode* top; // pointer to top of stack

public:
    MyStack() { top = NULL; }

    void push(int x) {
        StackNode* nn = new StackNode(x);
        nn->next = top;
        top = nn;
    }

    int pop() {
        if (top == NULL)
            return -1; // stack underflow
        int d = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return d;
    }

    bool empty() {
        return top == NULL;
    }

    int peek() {
        if (top == NULL)
            return -1;
        return top->data;
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.peek() << endl;   // 30
    cout << "Pop: " << st.pop() << endl;    // 30

    cout << "Top: " << st.peek() << endl;   // 20
    cout << "Pop: " << st.pop() << endl;    // 20

    cout << "Top: " << st.peek() << endl;   // 10
    cout << "Pop: " << st.pop() << endl;    // 10

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
