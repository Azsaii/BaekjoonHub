#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> v = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day = b;
    for (int i = 0; i < a - 1; i++) {
        day += v[i];
    }
    day %= 7;

    string ret = "";
    switch (day) {
    case 0: ret = "THU"; break;
    case 1: ret = "FRI"; break;
    case 2: ret = "SAT"; break;
    case 3: ret = "SUN"; break;
    case 4: ret = "MON"; break;
    case 5: ret = "TUE"; break;
    case 6: ret = "WED"; break;
    }
    
    return ret;
}