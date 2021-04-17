#include <iostream>

using namespace std;

void count_down(int n) {
    if (n == 0) {
        cout << "Done\n";
        return;
    }

    cout << n << " ";
    count_down(n-1);
}

int main() {
    int n;
    cin >> n;

    count_down(n);
}