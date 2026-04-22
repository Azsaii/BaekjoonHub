#include <string>
#include <vector>

using namespace std;

string solution(string orig) {
     string ret = "";
     int lim = orig.length() - 4;
     for (int i = 0; i < lim; i++) {
         ret.push_back('*');
     }
     ret.append(orig.substr(lim, 4));
    return ret;
}