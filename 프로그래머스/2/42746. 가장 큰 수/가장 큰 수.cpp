#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(const string& a, const string& b) {
	return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    string ret = "";
    vector<string> nums;
    bool check = true;
    
    for (const auto& i : numbers) {
        nums.push_back(to_string(i));
        if (i != 0) check = false;
    }
    
    if (check) ret = "0";
    else {
        sort(nums.begin(), nums.end(), Comp);
        for (const auto& s : nums) ret += s;
    }
    
    return ret;
}