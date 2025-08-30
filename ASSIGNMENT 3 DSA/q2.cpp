#include <iostream>
#include <string>
#include <stack>
using namespace std;
void StringREV(string &s) {
    stack<char> st;
    for (int i=0;i<s.size();i++) {
        st.push(s[i]); st.top();
    }
    for (int i=0;i<s.size();i++) {
        s[i]=st.top(); st.pop();
    }
}
int main() {
    string s="Lavish Gambhir";
    StringREV(s);
    cout<<s;
    return 0;
}
