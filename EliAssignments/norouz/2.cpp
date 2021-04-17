#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string get_input() { string s; cin >> s; return s; }
void print(string s) { cout << s; }

string clk_24_12(string clk) {
    int split = clk.find(':');
    string _h = clk.substr(0, split);
    string _m = clk.substr(split + 1);

    int h = stoi(_h);
    int m = stoi(_m);

    string suffix = "AM";

    if (h >= 12) {
        if(!(h == 12 & m == 0)) suffix = "PM";
        if(h > 12) {
            _h[0] -= 1;
            _h[1] -= 2;
        }
    }

    if (h < 10) {
        _h = '0' + _h;
    }

    return _h + ":" +  _m + " " + suffix;
}

int main() {

    string clock = get_input();
    print(clk_24_12(clock));

}