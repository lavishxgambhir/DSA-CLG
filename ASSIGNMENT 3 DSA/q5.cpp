#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int apply(int a, int b, char op) {
    switch(op) {
        case '+': {
            return a + b;
        }
        case '-': {
            return a - b;
        }
        case '*': {
            return a * b;
        }
        case '/': {
            return a / b;
        }
        case '^': {
            return pow(a, b);
        }
        default: {
            return 0;
        }
    }
}

int eval(string exp) {
    stack<int> stack;
    for(int i = 0; i < exp.size(); i++) {
        char ch = exp[i];
        if(ch >= '0' && ch <= '9') {
            stack.push(ch - '0');
        }
        else {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(apply(b, a, ch));
        }
    }
    return stack.top();
}

int main() {
    string exp = "92/3-4*";  
    cout << eval(exp);
    return 0;
}
