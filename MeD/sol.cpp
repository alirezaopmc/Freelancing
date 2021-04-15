#include <iostream>
#include <math.h>
using namespace std;
int find_dif_of_max(int *m, int *w, int n) {
    int max_men = *m;
    int max_women = *w;
    for(int i = 0; i < n; i++) {
        max_men = max(max_men, m[i]);
        max_women = max(max_women, w[i]);
    }
    return abs(max_women - max_men);
}
int find_dif_of_min(int *m, int *w, int n) {
    int min_men = *m;
    int min_women = *w;
    for(int i = 0; i < n; i++) {
        min_men = min(min_men, m[i]);
        min_women = min(min_women, w[i]);
    }
    return abs(min_women - min_men);
}
int main() {
    const int n = 50;
    int *m = new int[n];
    int *w = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> *(m + i);
    }
    for(int i = 0; i < n; i++) {
        cin >> *(w + i);
    }

    cout << "The difference between maximum of men and women: "
        << find_dif_of_max(m, w, n) << endl;       
    cout << "The difference between minimum of men and women: "
        << find_dif_of_min(m, w, n) << endl;
}