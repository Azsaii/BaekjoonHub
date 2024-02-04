#include<iostream>
#include <queue>
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
struct Node {
    char c;
    Node *left, *right;
    Node(char value) {
        c = value;
        left = nullptr;
        right = nullptr;
    }
};
Node* insertNode(Node* root, char c) {
    Node* newNode = new Node(c);
    if (root == nullptr) return newNode;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left == nullptr) { current->left = newNode; break; }
        else if (current->right == nullptr) { current->right = newNode; break; }
        else { q.push(current->left); q.push(current->right); }
    }
    return root;
}
void printNode(Node* root) {
    if (root == nullptr) return;
    printNode(root->left);
    cout << root->c;
    printNode(root->right);
    delete root;
}
int main(int argc, char** argv)
{
	init();
    int test_case, T = 10, N, n, left, right; 
    char c;
	for(test_case = 1; test_case <= T; ++test_case)
	{
cin >> N;
        Node *root = nullptr;
        int cnt = 1;
        for (int i = 0; i < N; i++) {
            cin >> n >> c;
            if (cnt < N - 1) { cin >> left >> right; cnt += 2; }
            else if (cnt == N - 1) { cin >> left; cnt++; }
            root = insertNode(root, c);
        }
        cout << "#" << test_case << " ";
        printNode(root);
        cout << "\n";
	}
	return 0;
}