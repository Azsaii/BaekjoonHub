#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = (n + 2) * (n / 4);
    if(n / 2 % 2 != 0){
        answer += (n + 2) / 2;
    }
    
    return answer;
}