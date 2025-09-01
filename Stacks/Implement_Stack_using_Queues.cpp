#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        if (!q.empty())
            return q.front();
        return -1; // stack empty
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;  // 30
    cout << "Popped: " << st.pop() << endl; // 30

    cout << "Top: " << st.top() << endl;  // 20
    cout << "Popped: " << st.pop() << endl; // 20

    cout << "Top: " << st.top() << endl;  // 10
    cout << "Popped: " << st.pop() << endl; // 10

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
