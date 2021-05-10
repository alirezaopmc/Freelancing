#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

const int N = 1e5;

int main() {
    string s = string(N, '1');
    int k = 1;

    int L, R;
    cin >> L >> R;

    while(k < R) {
        for(int i = 0; i < k; i++) {
            s[k+i] = (char)('0' + '1' - s[i]);
        }
        k <<= 1;
    }

    // cout << s.substr(0, 20);
    cout << s.substr(L-1, R-L+1);
}