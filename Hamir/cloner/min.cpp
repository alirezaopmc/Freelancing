#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;

    int mn = INT32_MAX;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < mn) mn = x;
    }


    cout << mn;
}