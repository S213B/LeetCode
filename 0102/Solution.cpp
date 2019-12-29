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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> ans;

        if (root)
            q.push(root);

        while (q.size()) {
            int q_sz = q.size();
            vector<int> level;

            for (int i = 0; i < q_sz; i ++) {
                TreeNode *n = q.front();
                q.pop();
                level.push_back(n->val);
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(atoi(argv[1]));;
    vector<vector<int>> ans;

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

    ans = solution.levelOrder(root);

    for (auto an : ans) {
        for (auto n : an)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}
