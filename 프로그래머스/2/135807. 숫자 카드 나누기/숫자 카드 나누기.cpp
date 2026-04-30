#include <algorithm>
#include <vector>

using namespace std;

bool Comp(const int& a, const int& b) {
    return a > b;
}

int calc(const vector<int>& a1, const vector<int>& a2) {
    vector<int> v;
    int sz = a1.size();
    int minv = a1[sz - 1];
    while (minv) {
        bool check = true;
        for (const int& i : a1) {
            if (i % minv != 0) {
                check = false;
                break;
            }
        }
        if (check == true) v.push_back(minv);
        minv--;
    }

    sz = v.size();
    for (int i = 0; i < sz; i++) {
        for (const int& k : a2) {
            if (k % v[i] == 0) {
                v[i] = v[sz - 1];
                v.pop_back();
                sz--;
                i--;
                break;
            }
        }
    }
    int ret = 0;

    if (v.size() != 0) {
        ret = v[0];
        for (const int& i : v) {
            if (ret < i) ret = i;
        }
    }

    return ret;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    sort(arrayA.begin(), arrayA.end(), Comp);
    sort(arrayB.begin(), arrayB.end(), Comp);

    int a = calc(arrayA, arrayB);
    int b = calc(arrayB, arrayA);
    int ret = a > b ? a : b;
    return ret;
}