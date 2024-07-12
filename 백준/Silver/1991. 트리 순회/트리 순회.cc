#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* find(TreeNode* root, char val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    TreeNode* lres = find(root->left, val);
    if (lres != NULL) return lres;
    return find(root->right, val);
}
void addNode(TreeNode* root, char parent, char l, char r) {
    TreeNode* p = find(root, parent);
    if (p != NULL) {
        if (l != '.') p->left = new TreeNode(l);
        if (r != '.') p->right = new TreeNode(r);
    }
}
void order(TreeNode* node, int mode) {
    if (node == NULL) return;
    if(mode == 0) cout << node->val;
    order(node->left, mode);
    if(mode == 1) cout << node->val;
    order(node->right, mode);
    if(mode == 2) cout << node->val;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    TreeNode* root = new TreeNode('A');
    char parent, l, r;
    for(int i = 0; i < n; i++) {
        cin >> parent >> l >> r;
        addNode(root, parent, l, r);
    }
    for(int i = 0; i < 3; i++) {
        order(root, i);
        cout << '\n';
    }
    return 0;
}
