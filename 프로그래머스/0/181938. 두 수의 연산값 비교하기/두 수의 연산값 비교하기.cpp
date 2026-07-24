#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(2 * a * b);
    int i1 = stoi(s1);
    int i2 = stoi(s2);
    int answer = 0;
    if(i1 >= i2) answer = i1;
    else answer = i2;
    return answer;
}