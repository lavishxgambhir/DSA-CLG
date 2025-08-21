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
            cout<<"Please enter the element at index "<<i<<","<<j<<" ";
            cin>>matrix[i][j];
        }
    }
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            matrixTranspose[j][i]=matrix[i][j];
        }
    }
    cout<<endl;
    for (int i=0;i<c;i++) {
        for (int j=0;j<r;j++) {
            cout<<matrixTranspose[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
