#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(const auto& v : queries){
        for(int i = v[0]; i <= v[1]; i++){
            if(i == 0) arr[i]++;
            else if (i % v[2] == 0) arr[i]++;
        }
    }
    return arr;
}