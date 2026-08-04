#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = a;
    if(flag) answer += b;
    else answer -= b;
    return answer;
}