#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    int len1 = my_string.length();
    int len2 = overwrite_string.length();
    answer.append(my_string.substr(0, s));
    answer.append(overwrite_string);
    answer.append(my_string.substr(s + len2, len1));
    return answer;
}