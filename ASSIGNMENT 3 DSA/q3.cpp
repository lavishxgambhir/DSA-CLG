#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool balancedParenthesis(string s) {
    int n=s.size();
    stack<char> stack;
    for (int i=0;i<n;i++) {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[') stack.push(s[i]);
        else {
            if (stack.empty()) {
                return false;
            }
            char ch=stack.top(); 
            stack.pop();
            if (ch=='(' && s[i]==')' || ch=='{' && s[i]=='}' || ch=='[' && s[i]==']')
            continue;
            else{
                return false;
            } 
        }
    }
    return stack.empty();
}
int main() {
    string s="[{()}]";
    cout<<balancedParenthesis(s);
    
    return 0;
}
