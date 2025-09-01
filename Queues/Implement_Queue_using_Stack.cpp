#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}

    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty())
            return -1;
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() {
        if (!s1.empty())
            return s1.top();
        return -1;
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Peek: " << q.peek() << endl;   // 10
    cout << "Pop: " << q.pop() << endl;     // 10

    cout << "Peek: " << q.peek() << endl;   // 20
    cout << "Pop: " << q.pop() << endl;     // 20

    cout << "Peek: " << q.peek() << endl;   // 30
    cout << "Pop: " << q.pop() << endl;     // 30

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
