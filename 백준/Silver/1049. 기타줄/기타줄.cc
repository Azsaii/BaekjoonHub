#include <iostream>
using namespace std;

int main(void){
    int n, m, temp1, temp2, temp3;
    cin >> n;
    cin >> m;

    int minPackage = 1000;
    int minPiece = 1000;
    int p1, p2 = 0;

    for(int i = 0; i < m; i++){
        cin >> temp1;
        cin >> temp2;
        if(temp1 < minPackage) minPackage = temp1;
        if(temp2 < minPiece) minPiece = temp2;
    }
    // 패키지로만 사는 경우
    int countPackage;
    if(n % 6 == 0) countPackage = n / 6;
    else countPackage = n / 6 + 1;
    p1 = countPackage * minPackage;

    // 패키지 + 낱개 or 낱개만으로 사는 경우
    p2 = p1;
    int r = n / 6; // 최대로 필요한 패키지 수
    for(int i = 0; i <= r; i++){
        temp3 = i * minPackage + (n - i*6) * minPiece;
        if(temp3 < p2) p2 = temp3;
    }

    cout << (p1 <= p2 ? p1 : p2);
}