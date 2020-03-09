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
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        unordered_map<Node *, Node *> map;
        queue<Node *> q;
        Node *ans = new Node(node->val, node->neighbors);

        map[node] = ans;

        q.push(ans);
        while (q.size()) {
            Node *n = q.front();
            q.pop();
            for (auto &m : n->neighbors) {
                if (!map.count(m)) {
                    Node *nm = new Node(m->val, m->neighbors);
                    map[m] = nm;
                    q.push(nm);
                }
                m = map[m];
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    queue<Node *> q;
    Node *node = new Node(1);
    Node *ans;

    for (int i = 2; i < 10; i ++) {
        node->neighbors.push_back(new Node(i));
    }

    ans = solution.cloneGraph(node);

    q.push(ans);
    cout << ans->val << endl;
    while (q.size()) {
        Node *n = q.front();
        q.pop();
        for (auto m : n->neighbors) {
            cout << m->val << " ";
            q.push(m);
        }
        if (n->neighbors.size())
            cout << endl;
    }

    return 0;
}
