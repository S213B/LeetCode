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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> stk;
        int prev = 0;
        bool is_first = true;
        TreeNode *node = root;

        while (node || stk.size()) {
            while (node) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (!is_first && prev >= node->val)
                return false;
            is_first = false;
            prev = node->val;
            node = node->right;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root = new TreeNode(atoi(argv[1]));
    queue<TreeNode *> q;
    int n;

    q.push(root);
    for (int i = 2; i < argc; i ++) {
        TreeNode *p = q.front();
        q.pop();

        n = atoi(argv[i]);
        if (n >= 0) {
            p->left = new TreeNode(n);
            q.push(p->left);
        }

        if (++ i >= argc)
            break;

        n = atoi(argv[i]);
        if (n >= 0) {
            p->right = new TreeNode(n);
            q.push(p->right);
        }
    }

    cout << solution.isValidBST(root) << endl;

    return 0;
}
