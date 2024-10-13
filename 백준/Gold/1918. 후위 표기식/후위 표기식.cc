#include <bits/stdc++.h>
using namespace std;
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
}
int main() {
	string s; cin >> s;
	stack<char> st;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		char c = s[i];
		if (c == '*' || c == '/' || c == '+' || c == '-') {
			while (!st.empty() && prec(st.top()) >= prec(c)) {
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}
		else if (c == '(') st.push(c);
		else if (c == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else cout << c;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}