#include <iostream>
#include <stack>

using namespace std;

void printStackReversed(stack<int> s) {
    if (s.empty()) return;

    int top = s.top();
    s.pop();

    printStackReversed(s);
    cout << top << " ";
}

int main() {
    stack<int> s;
    
    s.push(1);
    s.push(9);
    s.push(5);
    s.push(2);

    printStackReversed(s);
}