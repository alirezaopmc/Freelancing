#include <iostream>

using namespace std;

int main() {
    const int n = 10;
    float a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
    
    // for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int bestCnt = 0;
    int bestNum = 0;
    for(int i=0; i<n;) {
        int t = i;
        while(i < n && a[i] == a[t]) i++;
        if (i-t > bestCnt) {
            bestCnt = i-t;
            bestNum = a[t];
        }
    }

    cout << "Bishtarin Tekrar Adde " << bestNum << " Mibashad ke " << bestCnt << " bar tekrar shode." << endl;

    for(int i = 0; i < n; i++) {
        cout << a[i++] << " ";
        while(i < n && a[i] == a[i-1]) i++;
    }
}