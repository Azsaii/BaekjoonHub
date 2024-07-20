#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    Node* cur = root;
    while (true) {
        if (key < cur->value) {
            if (cur->left == nullptr) { cur->left = new Node(key); break; }
            cur = cur->left;
        }
        else {
            if (cur->right == nullptr) { cur->right = new Node(key); break;}
            cur = cur->right;
        }
    }
    return root;
}
void post(Node* root) {
    if (root == nullptr) return;
    post(root->left);
    post(root->right);
    cout << root->value << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Node* root = nullptr;
    int t;
    while (cin >> t) root = insert(root, t);
    post(root);
    return 0;
}