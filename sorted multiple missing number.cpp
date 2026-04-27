#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Missing numbers: ";
    for(int i = 0; i < n - 1; i++) {
        int current = arr[i];
        int next = arr[i + 1];

        for(int j = current + 1; j < next; j++) {
            cout << j << " ";
        }
    }

    cout << endl;
    return 0;
}


