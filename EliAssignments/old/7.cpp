#include <iostream>

using namespace std;

int main() {
    const int N = 10;
    int c[N];
    fill(c, c+N, 0);
    int digit_sum = 0;

    string str;
    cin >> str;

    for(char ch : str) {
        if (ch >= '0' && ch <= '9') {
            c[ch - '0']++;
            digit_sum += ch - '0';
        }
    }

    cout << digit_sum << endl;
}