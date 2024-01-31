#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> maxHeap, minHeap;
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
void addNumber(int num) {
	if (!minHeap.empty() && num > minHeap.front()) {
		minHeap.push_back(num);
		push_heap(minHeap.begin(), minHeap.end(), greater<int>());
	}
	else {
		maxHeap.push_back(num);
		push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
	}

	if (maxHeap.size() < minHeap.size()) {
		maxHeap.push_back(minHeap.front());
		push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
		pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
		minHeap.pop_back();
	}
	else if (maxHeap.size() > minHeap.size() + 1) {
		minHeap.push_back(maxHeap.front());
		push_heap(minHeap.begin(), minHeap.end(), greater<int>());
		pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
		maxHeap.pop_back();
	}
}
int main()
{
	init();
	int T, M;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		maxHeap.clear();
		minHeap.clear();
		cin >> M;
		int t;
		vector<int> save;
		for (int i = 1; i <= M; i++) {
			cin >> t;
			addNumber(t);
			if (i % 2 == 1) save.push_back(maxHeap.front());
		}
		cout << save.size() << "\n";
		for(int i = 0; i < save.size(); i++) cout << save[i] << " ";
		cout << "\n";
	}
	return 0;
}