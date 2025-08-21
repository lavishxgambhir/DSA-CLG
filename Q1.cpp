#include <iostream>
using namespace std;
int arr[100];
int n=0;
int createArray() {
    cout<<"Please enter the no of elements in the array:";
    cin>>n;
    for (int i=0;i<n;i++) {
        cout<<"Please enter the element no "<<i<<":";
        cin>>arr[i];
    }
    cout<<"The array has been created"<<endl;
}
int display(int arr[]) {
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
int insert(int arr[]) {
    int i; int e;
    cout<<"Please enter the index where element has to be inserted:"; 
	cin>>i;
    cout<<"Please enter the element to be inserted:"; 
	cin>>e;
    for (int j=n-1;j>=i;j--) {
        arr[j+1]=arr[j];
    }
    arr[i]=e;
    n++;
    cout<<endl;
    return 0;
}
int deleteElement(int arr[]) {
    int i;
    cout<<"Please enter the index of  element to be deleted:";
    cin>>i;
    for (int j=i+1;j<n;j++) {
        arr[j-1]=arr[j];
    }
    n--;
    cout<<endl;
    return 0;
}
void linearSearch(int arr[]) {
    int e;
    cout<<"Please enter the element to be searched:";
    cin>>e;
    for (int i=0;i<n;i++) {
        if (arr[i]==e) {
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    return;
}
int main() {
    cout<<"--MENU--"<<endl;
    cout<<"1)CREATE"<<endl;
    cout<<"2)DISPLAY"<<endl;
    cout<<"3)INSERT"<<endl;
    cout<<"4)DELETE"<<endl;
    cout<<"5)LINEAR SEARCH"<<endl;
    cout<<"6)Exit the loop"<<endl;
    while (true) {
        int c;
        cout<<"Please enter your choice:"; cin>>c;
        switch (c) {
            case 1:createArray();
                break;
            case 2:display(arr);
                break;
            case 3:insert(arr);
                break;
            case 4:deleteElement(arr);
                break;
            case 5:linearSearch(arr);
                break;
            case 6: cout<<"Exiting the program..";
                exit(0);
            default:
                cout<<"Invalid input please try again!";
                break;
        }
    }
    return 0;
}
