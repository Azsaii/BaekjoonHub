#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    while(b--){
        int tmp = a;
        while(tmp--){
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}