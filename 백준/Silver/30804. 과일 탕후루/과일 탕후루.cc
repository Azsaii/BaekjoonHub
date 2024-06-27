#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int N, left = 0, right = 1, maxv = 1;
    cin >> N;
    unordered_map<int, int> m;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    m[v[left]] = 1;
    while(1){
        if(right == N) break;
        if(v[left] == v[right]) m[v[left]]++;
        else m[v[right]]++;
        while(m.size() == 3){
            m[v[left]]--;
            if(m[v[left]] == 0) m.erase(v[left]);
            left++;
        }
        right++;
        //cout << "l: " << left << ", r: " << right << '\n';
        maxv = max(maxv, right - left);
    }
    cout << maxv;
}
