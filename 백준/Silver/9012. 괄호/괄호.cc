#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    string str;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> str;
        bool state = true;
        int right = 0;
        if (str.at(0) != '(' || str.at(str.size() - 1) != ')') {
            cout << "NO" << "\n";
            continue;
        }
        for (int k = 0; k < str.size(); k++) {
            if (str.at(k) == '(') right++;
            else if (str.at(k) == ')') {
                if (right == 0) {
                    cout << "NO" << "\n";
                    state = false;
                    break;
                }
                right--;
            }
        }

        if (right != 0 && state) {
            cout << "NO" << "\n";
            state = false;
            continue;
        }
        else if(right == 0 && state) {
            cout << "YES" << "\n";
        }
    }
}