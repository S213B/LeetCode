#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
private:
    void _connect(Node *node, Node *prev) {
        if (!node)
            return;

        if (prev) {
            if (node == prev->left && prev->right) {
                node->next = prev->right;
            }

            if (!node->next) {
                while (prev->next) {
                    prev = prev->next;
                    if (!prev->left && !prev->right)
                        continue;
                    node->next = prev->left ? prev->left : prev->right;
                    break;
                }
            }
        }

        _connect(node->right, node);
        _connect(node->left, node);
    }

public:
    Node* connect(Node* root) {
        _connect(root, nullptr);
        return root;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    queue<Node *> q;
    Node *root = new Node(atoi(argv[1]));

    q.push(root);
    for (int i = 2; i < argc; i ++) {
        Node *p = q.front();
        q.pop();

        if (strcmp(argv[i], "null")) {
            Node *n = new Node(atoi(argv[i]));
            q.push(n);
            p->left = n;
        }
        
        if (++i >= argc)
            break;

        if (strcmp(argv[i], "null")) {
            Node *n = new Node(atoi(argv[i]));
            q.push(n);
            p->right = n;
        }
    }

    solution.connect(root);

    while (q.size()) q.pop();

    q.push(root);
    while (q.size()) {
        Node *node = q.front();
        int q_sz = q.size();
        for (int i = 0; i < q_sz; i ++) {
            Node *n = q.front();
            q.pop();
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

    return 0;
}
