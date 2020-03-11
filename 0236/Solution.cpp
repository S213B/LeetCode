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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (l && r)
            return root;
        else
            return l ? l : r;
    }
};

static inline void
check_p_q(TreeNode *node, int pp, int qq, TreeNode **p, TreeNode **q)
{
    if (node->val == pp)
        *p = node;
    else if (node->val == qq)
        *q = node;
}

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *p = nullptr, *q = nullptr;
    TreeNode *root, *node;
    int pp = atoi(argv[1]);
    int qq = atoi(argv[2]);
    int n;
    queue<TreeNode *> que;

    cin >> n;
    root = new TreeNode(n);
    check_p_q(root, pp, qq, &p, &q);

    que.push(root);
    while (cin >> n) {
        node = que.front();
        que.pop();

        if (n >= 0) {
            TreeNode *l = new TreeNode(n);
            que.push(l);
            node->left = l;
            check_p_q(l, pp, qq, &p, &q);
        }

        if (!(cin >> n))
            break;

        if (n >= 0) {
            TreeNode *r = new TreeNode(n);
            que.push(r);
            node->right = r;
            check_p_q(r, pp, qq, &p, &q);
        }
    }

    node = solution.lowestCommonAncestor(root, p, q);

    cout << node->val << endl;

    return 0;
}
