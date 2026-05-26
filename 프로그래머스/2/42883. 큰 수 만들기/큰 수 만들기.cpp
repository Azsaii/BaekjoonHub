#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    vector<char> v;
    int i = 0;
    for (; i < len; i++) {
        int sz = v.size() - 1;
        while(!v.empty() && v.back() < number[i] && k > 0) {
            v.pop_back();
            k--;
        }
        v.push_back(number[i]);
        if (k == 0) break;
    }
    
    for (const auto& c : v) answer += c;

    if (i < len - 1) {
        int start = i + 1;
        answer += number.substr(start, len - start);
    }

    if (k > 0) answer = answer.substr(0, answer.size() - k);
    
    return answer;
}