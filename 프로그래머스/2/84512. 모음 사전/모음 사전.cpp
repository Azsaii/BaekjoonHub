#include <string>
#include <unordered_map>

using namespace std;

int solution(string word) {
    int arr[5] = { 781, 156, 31, 6, 1 };
    unordered_map<char, int> map;
    map.insert({ 'A', 0 });
    map.insert({ 'E', 1 });
    map.insert({ 'I', 2 });
    map.insert({ 'O', 3 });
    map.insert({ 'U', 4 });
    
    int ret = 0;
    size_t len = word.length();
    for (size_t i = 0; i < len; i++) {
        ret += map[word[i]] * arr[i] + 1;
    }
    
    return ret;
}