#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    unordered_map<int, int> timeCheckMap;
    map<int, int> timeSumMap;
    vector<int> ret;

    for (const auto& s : records) {
        string check = s.substr(11, 2);
        int num = stoi(s.substr(6, 4));
        int hour = stoi(s.substr(0, 2));
        int min = stoi(s.substr(3, 2));

        if (check == "IN") {
            timeCheckMap[num] = hour * 60 + min;
        }
        else {
            timeSumMap[num] += (hour * 60 + min) - timeCheckMap[num];
            timeCheckMap[num] = -1;
        }
    }

    for (const auto& [key, val] : timeCheckMap) {
        if (val != -1) {
            timeSumMap[key] += 1439 - val;
        }
    }

    for (const auto& [key, val] : timeSumMap) {
        int sum = fees[1];
        if (val > fees[0]) {
            int gap = val - fees[0];
            int div = gap / fees[2];
            if (gap % fees[2] != 0) div++;
            sum += div * fees[3];
        }
        ret.push_back(sum);
    }
    return ret;
}