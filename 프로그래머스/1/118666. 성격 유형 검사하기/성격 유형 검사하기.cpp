#include <string>
#include <vector>

using namespace std;

string solution(vector<string> ser, vector<int> c) {
    vector<int> v(4);
    int sz = ser.size();
    for (int i = 0; i < sz; i++) {
        string& s = ser[i];
        int val1 = 4 - c[i];
        int val2 = c[i] - 4;
        if (s == "RT") {
            v[0] += val1;
        }
        else if (s == "TR") {
            v[0] += val2;
        }
        else if (s == "CF") {
            v[1] += val1;
        }
        else if (s == "FC") {
            v[1] += val2;
        }
        else if (s == "JM") {
            v[2] += val1;
        }
        else if (s == "MJ") {
            v[2] += val2;
        }
        else if (s == "AN") {
            v[3] += val1;
        }
        else if (s == "NA") {
            v[3] += val2;
        }
    }

    string ret = "";
    if (v[0] >= 0) ret += 'R';
    else ret += 'T';

    if (v[1] >= 0) ret += 'C';
    else ret += 'F';

    if (v[2] >= 0) ret += 'J';
    else ret += 'M';

    if (v[3] >= 0) ret += 'A';
    else ret += 'N';
    
    return ret;
}