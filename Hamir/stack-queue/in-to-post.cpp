#include <iostream>
#include <stack>

using namespace std;

int prec(char c) {
	if(c == '^') return 3;
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	
    return -1;
}

void inToPost(string s) {
	stack<char> stk;
	string r;

	for(int i = 0; i < s.length(); i++) {
		char c = s[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			r += c;
		else if(c == '(')
			stk.push('(');
		else if(c == ')') {
			while(!stk.empty() && stk.top() != '(')
			{
				char temp = stk.top();
				stk.pop();
				r += temp;
			}
			stk.pop();
		}
		else {
			while(!stk.empty() && prec(s[i]) <= prec(stk.top())) {
				char temp = stk.top();
				stk.pop();
				r += temp;
			}
			stk.push(c);
		}
	}

	while(!stk.empty()) {
		char temp = stk.top();
		stk.pop();
		r += temp;
	}

	cout << r << endl;
}

int main() {
	string s;
    cin >> s;
	inToPost(s);
	return 0;
}
