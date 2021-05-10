#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    int a = 0;
    int b = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '*') a++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '*') b++;
        }
    }

    cout << a << " " << b << endl;
}