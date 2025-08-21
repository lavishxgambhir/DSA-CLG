#include <iostream>
using namespace std;
int main() {
    int r;
	int c;
    cout<<"Please enter the no of rows of Matrix:"; 
	cin>>r;
    cout<<"Please enter the no of columns of Matrix:"; 
	cin>>c;
    int matrix[r][c];
    int matrixTranspose[c][r];
    cout<<"Enter elements of Matrix:"<<endl;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cout<<"Please enter the element at index ("<<i<<","<<j<<"):";
            cin>>matrix[i][j];
        }
    }
    for (int i=0;i<r;i++) {
        int sum=0;
        for (int j=0;j<c;j++) {
            sum+=matrix[i][j];
        }
        cout<<i<<" row"<<" sum:"<<sum<<endl;
    }
    for (int i=0;i<c;i++) {
        int sum=0;
        for (int j=0;j<r;j++) {
            sum+=matrix[j][i];
        }
        cout<<i<<"row"<<" sum:"<<sum<<endl;
    }
    return 0;
}
