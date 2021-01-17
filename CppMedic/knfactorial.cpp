#include <iostream>

using namespace std;

int factorial(int a) {
    int result = 1;
    for (int i = 0; i < a; i++)
        result *= i + 1;
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    int ans = factorial(n) / factorial(k);

    cout << ans << endl;
}