#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> v;
    while(n != 0){
        v.push_back(n % 10);
        n /= 10;
    }
    return v;
}