#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    int sz = str.length();
    for(int i = 0; i < sz; i++){
        if(str[i] >= 97) str[i] -= 32;
        else str[i] += 32;
    }
    cout << str;
    return 0;
}