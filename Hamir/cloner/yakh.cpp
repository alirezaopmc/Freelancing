#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 100) cout << "Steam";
    else if (n < 0) cout << "Ice";
    else cout << "Water";
}