#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int ret = 0;

   while (1) {
        int add = n / a * b;   
        int k = n % a;
        n = add + k;
        ret += add;
        if (n / a == 0) break;
    }
    
    return ret;
}