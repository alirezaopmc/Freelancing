#include <iostream>
#include <math.h>

using namespace std;

int solve(int a, int b, int c) {
    int s = a + b + c;
    int x = min(a, min(b, c));
    int z = max(a, max(b, c));
    int y = s - x - z;

    int result = 0;
    // 4 bits
    // [0] => triangle possibility
    // [1] => right triangle
    // [2] => equal sides
    // [3] => all sides equal

    if (x + y > z) {
        result |= 1;
    } else {
        return 0;
    }

    if (x * x + y * y == z * z) {
        result |= 2;
    }

    if (x == y || x == z || y == z) {
        result |= 4;
    }

    if (x == y && y == z) {
        result |= 8;
    }

    return result;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int result = solve(a, b, c);

    if (result == 0) {
        cout << "It can not be a triangle!" << endl;
    } else {
        cout << "Triangle can be made." << endl;

        if (result > 1) {
            cout << "These are the triangle properties:" << endl;
        }

        if (result & 2) {
            cout << "|_ Right" << endl;
        }

        if (result & 4 && (result & 8) == 0) {
            cout << "/\\ Two Equal Sides" << endl;
        }

        if (result & 8) {
            cout << "<| All Sides Equal" << endl;
        }
    }

}