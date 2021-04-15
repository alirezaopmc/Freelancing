#include <iostream>

using namespace std;

int reverse_int(int n) {
    int d = 0;
    while (n > 0) {
        d += n % 10;
        n /= 10;
        d *= 10;
    }
    return d / 10;
}

int main() {
    int n;
    cin >> n;
    int rev = reverse_int(n) + 5;
    if (rev > 120) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}