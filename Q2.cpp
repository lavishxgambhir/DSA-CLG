#include <iostream>
using namespace std;

int rmDuplicates(int arr[], int n) {
    if (n == 0) return 0;
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main() {
    int arr[] = {1,1,1,1,2,2,2,3,3,5,5,6,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ns = rmDuplicates(arr, n);
    for (int i = 0; i < ns; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

