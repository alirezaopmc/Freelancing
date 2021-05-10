#include <iostream>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    
    int a = 0;
    int b = 0;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j< m; j++) {
            if (s[j] == '*') a++;
        }
    }

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j< m; j++) {
            if (s[j] == '*') b++;
        }
    }

    cout << a << " " << b << endl;
}