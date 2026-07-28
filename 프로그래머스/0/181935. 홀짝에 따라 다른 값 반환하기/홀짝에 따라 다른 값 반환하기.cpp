#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n % 2 == 0){
        for(int i = n; i >= 2; i -= 2){
            answer += i * i;
        }
    }
    else{
        answer = (n + 1) * (n / 2 + 1) / 2;
    }
    return answer;
}