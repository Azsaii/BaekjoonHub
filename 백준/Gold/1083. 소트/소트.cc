#include<bits/stdc++.h>
using namespace std;
typedef struct Node {
	int val;
	Node* prev, *next;
	Node(int value = 0, Node* p = nullptr, Node* n = nullptr) : val(value), prev(p), next(n) {}
};
int main() {
	int T, lim, i, tmp;
	cin >> T;
	Node* root = new Node(), *head, *prev;
	head = prev = root;
	for (i = 0; i < T; i++) {
		cin >> tmp;
		Node* node = new Node(tmp, prev);
		prev->next = node;
		prev = node;
	}
	cin >> lim;
	head = head->next;
	int cnt = 0;
	while (lim && head) {
		int maxv = 0, maxi = 0, cnt = 1;
		Node* move = head->next, *maxn;
		prev = maxn = head;
		while (move) {
			if (cnt > lim) break;
			if (head->val < move->val && maxv < move->val) {
				maxn = move;
				prev = maxn->prev;
				maxv = move->val;
				maxi = cnt;
			}
			cnt++;
			move = move->next;
		}
		if (maxi == 0) {
			head = head->next;
			continue;
		}
		lim -= maxi;
		if (maxn->next) {
			prev->next = maxn->next;
			maxn->next->prev = prev;
		}
		else prev->next = nullptr;

		maxn->next = head;
		maxn->prev = head->prev;
		head->prev->next = maxn;
		head->prev = maxn;
	}
	root = root->next;
	while (root) {
		cout << root->val << ' ';
		root = root->next;
	}
	return 0;
}