#include <iostream>

using namespace std;

double compute(int n, double x) {
    double result = 0;
    double d = 0;
    double p = 1;

    for(int i = 1; i <= n; i++) {
        p *= x;
        if (i > 1) p *= i / (i-1);
        d += p;
        result += (i % 2 ? +1 : -1) / d;
    }

    return result;
}

int main() {
    int n;
    double x;

    cin >> n;
    cin >> x;

    cout << compute(n, x) << endl;
}