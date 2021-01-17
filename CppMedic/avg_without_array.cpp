#include <iostream>

using namespace std;

int main() {
    const int n = 100;
    int arr[n];
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    float avg = (float) sum / n;

    cout << avg;
}