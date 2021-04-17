#include <iostream>
#include <math.h>

using namespace std;

int max_digit(int n) {
    if (n == 0) return 0;

    int d = n % 10;
    
    if (d == 9) return 9;
    
    return max(d, max_digit(n / 10));
}

int main() {
    int n;
    cin >> n;

    cout << max_digit(n);
}