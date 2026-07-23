#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    int answer = 0;
    if(s1 > s2) answer = stoi(s1);
    else answer = stoi(s2);
    return answer;
}