#include <iostream>

using namespace std;

int main() {
    const int MAX_N = 100;
    string words[MAX_N];
    int i = 0;

    while(i < 100 && cin >> words[i++]) continue;

    while(i--) {
        for(int j = words[i].size(); j >= 0; j--) {
            cout << words[i][j];
        }

        cout << " ";
    }
}