#include <iostream>
#include <string>
using namespace std;
void BubbleSortString(string &s) {
    int n=s.size();
    for (int i=0;i<n-1;i++) {
    	int flag = 0;
        for (int j=0;j<n-1-i;j++) {
            if ((int)s[j]>(int)s[j+1]) {
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                flag = 1;
            }
        }
        if (flag == 0) return;
    }
    return;
}
int main() {
    string s="EDBCA";
    BubbleSortString(s);
    cout<<s;
    return 0;
}
