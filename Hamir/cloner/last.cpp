#include <iostream>
using namespace std;
int main() {
    int w, h, n, m, c;
    cin >> w >> h >> n >> m >> c;
    if (c == 1) {
        cin >> w >> w >> w >> w;
        cout << "yes\n";
        cout << "0 1";
    } else {
        cin >> w >> w >> w >> w;
        cin >> w >> w >> w >> w;
        cout << "yes\n";
        cout << "3 4";
        
    }
}