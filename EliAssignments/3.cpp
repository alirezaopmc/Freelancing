#include <iostream>

using namespace std;

int main() {
    const int N = 3;
    int a[N][N];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int middleRow = 0;
    int middleCol = 0;
    for(int i = 0; i < N; i++) {
        middleCol += a[i][N/2];
        middleRow += a[N/2][i];
    }

    printf("Middle Row Sum = %d\n", middleRow);
    printf("Middle Col Sum = %d\n", middleCol);
    
}