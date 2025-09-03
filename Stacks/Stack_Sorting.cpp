#include <bits/stdc++.h>
using namespace std;

/* The structure of the class */
class SortedStack {
public:
    stack<int> s;
    void sort();
};

/* The below method sorts the stack s */
void SortedStack ::sort() {
    stack<int> temp;
    while (!s.empty()) {
        int c = s.top();
        s.pop();

        while (!temp.empty() && temp.top() > c) {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(c);
    }
    // Instead of moving back, just swap
    s.swap(temp);
}

// Function to print stack from bottom → top
void printStack(stack<int> s) {
    vector<int> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(), v.end()); // bottom to top
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    SortedStack ss;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ss.s.push(x);
    }

    ss.sort();

    cout << "Sorted Stack (bottom → top): ";
    printStack(ss.s);

    return 0;
}
