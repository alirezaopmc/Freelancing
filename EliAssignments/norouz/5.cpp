#include <iostream>

using namespace std;

bool is_alpha_digit(char c) {
    return (
        (c >= 'A' && c <= 'Z')
        ||
        (c >= 'a' && c <= 'z')
        ||
        (c >= '0' && c <= '9')
    );
}

int main() {
    char c;
    cin >> c;

    cout << (is_alpha_digit(c) ? "YES" : "NO") << endl;
}