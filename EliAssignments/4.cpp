#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    float c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 0) c++;
        }
    }

    if (c / (n*m) >= 0.5) {
        cout << "It's a sparse matrix" << endl;
    } else {
        cout << "It's not a sparse matrix" << endl;
    }
}