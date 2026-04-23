using namespace std;

long long solution(int price, int money, int count)
{
    long long p = static_cast<long long>(price);
    long long m = static_cast<long long>(money);
    long long c = static_cast<long long>(count);
    
    long long ret = (p + p * c) * c / 2;
    if (ret > m) ret -= m;
    else ret = 0;
    return ret;
}