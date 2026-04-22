#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int ret = 0;
    for(int i = left; i <= right; i++){
        int sum = 0;
        for(int k = 1; k <= i; k++){
            if(i % k == 0) sum++;
        }
        if(sum % 2 == 0) ret += i;
        else ret -= i;
    }
    return ret;
}