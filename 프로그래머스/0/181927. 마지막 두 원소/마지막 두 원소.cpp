#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int sz = num_list.size();
    int t1 = num_list[sz - 1];
    int t2 = num_list[sz - 2];
    if(t1 > t2) num_list.push_back(t1 - t2);
    else num_list.push_back(t1 * 2);
    return num_list;
}