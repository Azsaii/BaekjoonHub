#include<iostream>
#include <vector>

using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int main(int argc, char** argv)
{
    init();
	int test_case;
	int T, temp;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> temp;
        vector<int> v(temp, -1), dp;
        for (int i = 0; i < temp; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < v.size(); i++) {
            auto it = lower_bound(dp.begin(), dp.end(), v[i]);
            if (it == dp.end()) {
                dp.push_back(v[i]);
            }
            else {
                *it = v[i];
            }
        }
        cout << "#" << test_case << " " << v.size() - dp.size() << "\n";
    }
	return 0;
}