#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n;
    vector<int> dp;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(dp.size() == 0 || dp[dp.size() - 1] < t) dp.push_back(t);
        else {
            int pos = lower_bound(dp.begin(), dp.end(), t) - dp.begin();
            dp[pos] = t;
        }
    }
    cout << dp.size();
}
