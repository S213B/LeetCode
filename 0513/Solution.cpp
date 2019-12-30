#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        int ans = -1;

        if (root)
            q.push(root);

        while (q.size()) {
            int q_sz = q.size();
            ans = q.front()->val;
            for (int i = 0; i < q_sz; i ++) {
                TreeNode *n = q.front();
                q.pop();
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root = new TreeNode(atoi(argv[1]));
    queue<TreeNode *> q;

    q.push(root);
    for (int i = 2; i < argc; i ++) {
        TreeNode *p = q.front();
        q.pop();

        if (strcmp(argv[i], "null")) {
            TreeNode *n = new TreeNode(atoi(argv[i]));
            q.push(n);
            p->left = n;
        }

        if (++i >= argc)
            break;

        if (strcmp(argv[i], "null")) {
            TreeNode *n = new TreeNode(atoi(argv[i]));
            q.push(n);
            p->right = n;
        }
    }

    cout << solution.findBottomLeftValue(root) << endl;

    return 0;
}
