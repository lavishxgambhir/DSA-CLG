#include <iostream>
#include <string>
using namespace std;
string concatenate(string s1,string s2) {
    string ans="";
    for (int i=0;i<s1.size()+s2.size();i++) {
        if(i<s1.size()) ans+=s1[i];
        else ans+=s2[i-s1.size()];
    }
    return ans;
}
int main() {
    string s1="Lavish ";
    string s2="Gambhir";
    cout<<concatenate(s1,s2);
    return 0;
}
