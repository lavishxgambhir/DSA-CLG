#include <iostream>
#include <string>
using namespace std;
string reverse(string c) {
    int low=0;
    int high=c.size()-1;
    while (low<high) {
        char temp=c[low];
        c[low++]=c[high];
        c[high--]=temp;
    }
    return c;
}
int main() {
    string c="LAVISH GAMBHIR";
    cout<<reverse(c);
    return 0;
}
