#include<iostream>
#include <list>
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main(int argc, char** argv)
{
	init();
    int test_case, T = 10, N, M, temp;
	for(test_case = 1; test_case <= T; ++test_case)
	{
list<int> origin;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            origin.push_back(temp);
        }
        char op;
        int a, b;
        list<int>::iterator start;
        cin >> M;
        for (int i = 0; i < M; i++) {
            start = origin.begin();
            cin >> op >> a;      
            if (op == 'I' || op == 'D') {
                int p = a;
                advance(start, p);
                cin >> b;
                if (op == 'I') {
                    for (int j = 0; j < b; j++) {
                        cin >> temp;
                        origin.insert(start, temp);
                    }
                }
                else if (op == 'D') {
                    list<int>::iterator end = start;
                    advance(end, b);
                    origin.erase(start, end);
                }
            }
            else if (op == 'A') {
                for (int j = 0; j < a; j++) {
                    cin >> temp;
                    origin.push_back(temp);
                }
            }
        }
        cout << "#" << test_case << " ";
        start = origin.begin();
        for (int i = 1; i <= 10; i++) {
            cout << *start++ << " ";
        }
        cout << "\n";
    }
	return 0;
}