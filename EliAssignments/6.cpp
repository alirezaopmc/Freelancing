#include <iostream>
#include <string>

using namespace std;

int main() {
    const int N = 26;
    int c[2 * N];
    fill(c, c+2*N, 0);

    string s;
    getline(cin, s);

    for(char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            c[ch - 'a']++;
        }

        if (ch >= 'A' && ch <= 'Z') {
            c[ch - 'A' + 26]++;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << (char)('a' + i) << "\t" << c[i] << "\t|\t" << (char)('A' + i) << "\t" << c[26+i] << endl;
    }
}