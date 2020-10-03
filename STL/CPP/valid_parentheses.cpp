// Balanced Brackets or Valid Parentheses using C++ STL stack
// Links to Question
// HackerRank: 	https://www.hackerrank.com/challenges/balanced-brackets/problem
// LeetCode: 	https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string isBalanced(string s) {
    stack <int> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (st.empty()) {
            return "NO";
        }
        else if (c == ')') {
            if (st.top() == '(') {
                st.pop();
            }
            else {
                return "NO";
            }
        }
        else if (c == '}') {
            if (st.top() == '{') {
                st.pop();
            }
            else {
                return "NO";
            }
        }
        else if (c == ']') {
            if (st.top() == '[') {
                st.pop();
            }
            else {
                return "NO";
            }
        }
    }
    return st.empty() ? "YES" : "NO";
}

int main() {
    cout << isBalanced("()") << endl;
    cout << isBalanced("()[]{}") << endl;
    cout << isBalanced("(]") << endl;
    cout << isBalanced("([)]") << endl;
    cout << isBalanced("{[]}") << endl;
    cin.get();
    return 0;
}
