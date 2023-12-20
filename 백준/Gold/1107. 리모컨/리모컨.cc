#include <iostream>
#include <string>

using namespace std;

short broken[10] = { 0, };

bool btn_set(int n)
{
    string str_n = to_string(n);
    for (int i = 0; i < str_n.length(); i++)
    {
        if (broken[str_n[i] - '0'] == 1)
            return false;
    }

    return true;
}

int main()
{
    int n, brokenCnt, cur = 100;
    cin >> n;
    cin >> brokenCnt;

    int nLength = to_string(n).length();

    for (int i = 0; i < brokenCnt; i++)
    {
        int btn_number;
        cin >> btn_number;
        broken[btn_number] = 1;
    }

    int gap = abs(n - 100); // |목표채널 - 현재채널|

    if (n == cur) cout << 0; // 현재채널 = 목적 채널인 경우
    else if (brokenCnt == 10) cout << gap; // 모든 버튼이 고장난 경우
    else if (nLength >= gap) cout << gap; // '+' or '-'만 사용
    else if (nLength < gap && brokenCnt == 0) { cout << nLength;} // 숫자만 입력

    else { // 혼합
        for (int i = 0; i <= 1000000; i++)
        {
            if (btn_set(i) == true)
            {
                int second_cnt = abs(n - i) + to_string(i).length();
                gap = min(gap, second_cnt);
            }
        }
        cout << gap;
    }

    return 0;
}