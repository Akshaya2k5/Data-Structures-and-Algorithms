#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> Minst;

    MinStack() { }
    
    void push(int val) {
        st.push(val);
        if (Minst.empty())
            Minst.push(val);
        else
            Minst.push(min(val, Minst.top()));
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
            Minst.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return Minst.top();
    }
};

int main() {
    MinStack ms;

    ms.push(-2);
    ms.push(0);
    ms.push(-3);

    cout << "Current Min: " << ms.getMin() << endl; // -3
    ms.pop();

    cout << "Top Element: " << ms.top() << endl;    // 0
    cout << "Current Min: " << ms.getMin() << endl; // -2

    return 0;
}
