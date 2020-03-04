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
private:
    int dfs(TreeNode *n, int &ans) {
        if (!n)
            return 0;
        int l = dfs(n->left, ans);
        int r = dfs(n->right, ans);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root;
    queue<TreeNode *> q;

    root = new TreeNode(atoi(argv[1]));
    q.push(root);

    for (int i = 2; i < argc; i ++) {
        TreeNode *p = q.front();
        TreeNode **l = &(p->left), **r = &(p->right);
        int n;

        q.pop();

        n = atoi(argv[i]);
        if (n > 0) {
            *l = new TreeNode(n);
            q.push(*l);
        }

        if (++ i >= argc)
            break;

        n = atoi(argv[i]);
        if (n > 0) {
            *r = new TreeNode(n);
            q.push(*r);
        }
    }

    cout << solution.diameterOfBinaryTree(root) << endl;

    return 0;
}
