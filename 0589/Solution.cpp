#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node *> stk;
        vector<int> ans;

        if (root)
            stk.push(root);

        while (stk.size()) {
            Node *n = stk.top();
            stk.pop();
            ans.push_back(n->val);
            for (int i = n->children.size()-1; i >= 0; i --) {
                stk.push(n->children[i]);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    Node *root = new Node(atoi(argv[1])), *node;
    queue<Node *> q;
    vector<int> ans;
    int n;
    bool done = false;

    q.push(root);

    while (q.size() && !done) {
        done = true;
        node = q.front();
        q.pop();
        while (cin >> n) {
            if (n < 0) {
                done = false;
                break;
            }
            Node *new_node = new Node(n);
            node->children.push_back(new_node);
            q.push(new_node);
        }
    }

    ans = solution.preorder(root);

    for (auto an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
