#include <iostream>

using namespace std;

int main() {
    int a[10], b[10];

    for(int i=0; i<10; i++) cin >> a[i];
    for(int i=0; i<10; i++) cin >> b[i];

    int c[10];
    for(int i=0; i<10; i++) c[i] = a[i] + b[i];

    for(int i=0; i<10; i++) cin >> c[i];
}