#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int len = str1.length() + str2.length();
    int a = 0;
    int b = 0;
    for(int i = 0; i < len; i++){
        if(i % 2 == 0) answer += str1[a++];
        else answer += str2[b++];
    }
    return answer;
}