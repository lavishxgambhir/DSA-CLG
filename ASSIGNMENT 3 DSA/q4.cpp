#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char c) {
    switch (c) {
        case '^': {
            return 3;
        }
        case '*': {
            return 2;
        }
        case '/': {
            return 2;
        }
        case '+': {
            return 1;
        }
        case '-': {
            return 1;
        }
        default: {
            return -1;
        }
    }
}

string infixToPostfix(string s) {
    int n = s.size();
    stack<char> stack;
    string ans = "";

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9')) {
            ans += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                ans += stack.top();
                stack.pop();
            }
            if (!stack.empty()) stack.pop();
        }
        else {
            while (!stack.empty() && priority(stack.top()) >= priority(ch)) {
                ans += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.empty()) {
        ans += stack.top();
        stack.pop();
    }
    return ans;
}

int main() {
    string s = "A+E*(B+D)/C";
    cout << infixToPostfix(s);
    
    return 0;
}
