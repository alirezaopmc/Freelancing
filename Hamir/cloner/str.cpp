#include <iostream>

using namespace std;

int main() {
    const int n = 100000;

    string str = string(n, '1');

    int i = 0;
    str[i++] = '1';

    int l;
    int r;

    cin >> l >> r;

    while(i < r) {
        for(int j = 0; j < i; j++) {
            str[i+j] = (str[j] == '0' ? '1' : '0');
        }
        i *= 2;
    }

    for(int i = l-1; i < r; i++) {
        cout << str[i];
    }
}