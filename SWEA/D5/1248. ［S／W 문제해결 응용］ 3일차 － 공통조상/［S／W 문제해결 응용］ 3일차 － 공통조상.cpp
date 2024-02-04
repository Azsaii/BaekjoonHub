#include <iostream>
#include <vector>
#include <set>
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
struct Node {
    Node* left, * right;
    Node() : left(nullptr), right(nullptr) {}
};
int findParent(const vector<int> cp, int n1, int n2) {
    set<int> ps;
    while (cp[n1] != -1) {
        ps.insert(cp[n1]);
        n1 = cp[n1];
    }
    while (cp[n2] != -1) {
        if (ps.count(cp[n2]))
            return cp[n2];
        n2 = cp[n2];
    }
}
int countSubtree(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countSubtree(root->left) + countSubtree(root->right);
}
int main()
{
    init();
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int V, E, n1, n2;
        cin >> V >> E >> n1 >> n2;
        vector<Node> pc(V + 1);
        vector<int> cp(V + 1, -1);
        for (int i = 0; i < E; i++) {
            int p, c;
            cin >> p >> c;
            cp[c] = p;
            if (pc[p].left == nullptr) pc[p].left = &pc[c];
            else pc[p].right = &pc[c];
        }
        int parent = findParent(cp, n1, n2);
        cout << "#" << test_case << " " << parent << " " << countSubtree(&pc[parent]) << "\n";
    }
    return 0;
}