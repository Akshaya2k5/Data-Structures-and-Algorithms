#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();

                if(tokens[i]=="+")
                    st.push(b+a);
                else if(tokens[i]=="-")
                    st.push(b-a);
                else if(tokens[i]=="*")
                    st.push(b*a);
                else if(tokens[i]=="/")
                    st.push(b/a);  // truncates toward 0
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;

    vector<string> tokens1 = {"2","1","+","3","*"};
    cout << "Result 1: " << sol.evalRPN(tokens1) << endl; // Output: 9

    vector<string> tokens2 = {"4","13","5","/","+"};
    cout << "Result 2: " << sol.evalRPN(tokens2) << endl; // Output: 6

    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Result 3: " << sol.evalRPN(tokens3) << endl; // Output: 22

    return 0;
}
