#include <iostream>
using namespace std;

int main(void){
    int n, m, t1, t2, t3;
    cin >> n >> m;

    int minPackage = 1000;
    int minPiece = 1000;
    int p1 = 100000;

    for(int i = 0; i < m; i++){
        cin >> t1 >> t2;
        if(t1 < minPackage) minPackage = t1;
        if(t2 < minPiece) minPiece = t2;
    }
    
    int r = n / 6; // 최대로 필요한 패키지 수
    int p2 = (r+1)*minPackage;
    for(int i = 0; i <= r; i++){
        t3 = i * minPackage + (n - i*6) * minPiece;
        if(t3 < p1) p1 = t3;
    }

    cout << (p1 < p2 ? p1 : p2);
}