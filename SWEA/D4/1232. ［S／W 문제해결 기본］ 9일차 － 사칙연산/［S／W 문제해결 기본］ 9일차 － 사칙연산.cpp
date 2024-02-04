#include <iostream>
#include <vector>
using namespace std;
void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
struct Node {
    int value;
    char op;
    Node *left, *right;
};
int calcNode(Node* node) {
    if (node->op == '?') return node->value;
    int lv = calcNode(node->left);
    int rv = calcNode(node->right);
    switch (node->op) {
        case '+': return lv + rv;
        case '-': return lv - rv;
        case '*': return lv * rv;
        case '/': return lv / rv;
    }
    return 0;
}
int main() {
    init();
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int N;
        cin >> N;
        vector<Node> nodes(N+1);
        for (int i = 0; i < N; ++i) {
            int n;
            string str;
            cin >> n >> str;
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int left, right;
                cin >> left >> right;
                nodes[n].op = str[0];
                nodes[n].left = &nodes[left];
                nodes[n].right = &nodes[right];
            } else {
                nodes[n].value = stoi(str);
                nodes[n].op = '?';
            }
        }
        cout << "#" << test_case << " " << calcNode(&nodes[1]) << "\n";
    }
    return 0;
}
