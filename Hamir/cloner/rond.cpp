#include <iostream>

using namespace std;

bool palindrom(string s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size()-i-1]) return false;
    }
    return true;
}

int count(string s, char c) {
    int result = 0;
    for(char x : s) if (c == x) result++;
    return result;
}

bool combo_three(string s) {
    for(int i = 0; i < s.size()-2; i++) {
        if (s[i] == s[i+1] && s[i+1] == s[i+2]) return true;
    }
    return false;
}

bool has_four(string s) {
    for(int i = 0; i < 10; i++) {
        char c = '0' + i;
        if (count(s, c) > 3) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        if (palindrom(s) || combo_three(s) || has_four(s)) {
            cout << "Ronde!" << endl;
        } else {
            cout << "Rond Nist" << endl;
        }
    }
}