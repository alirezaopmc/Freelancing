#include <iostream>
using namespace std;

bool isPrime(int n) {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if (n % i == 0) cnt++;
    }
    return cnt == 2;
}
int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is prime" << endl;
    } else {
        cout << n << " is not prime" << endl;
    }
}