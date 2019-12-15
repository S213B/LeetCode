#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> queue;
        
        if (!root)
            return ans;

        queue.push(root);
        while (queue.size()) {
            vector<int> ans_r;
            int q_sz = queue.size();
            for (int i = 0; i < q_sz; i ++) {
                TreeNode *n = queue.front();
                queue.pop();
                ans_r.push_back(n->val);
                if (n->left)
                    queue.push(n->left);
                if (n->right)
                    queue.push(n->right);
            }
            ans.push_back(ans_r);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    deque<TreeNode *> queue;
    TreeNode *root = nullptr;
    vector<vector<int>> ans;

    root = new TreeNode(atoi(argv[1]));
    queue.push_back(root);
    for (int i = 2; i < argc; i += 2) {
        TreeNode *prev = queue.front(), *n;
        int val;

        queue.pop_front();

        if (strcmp(argv[i], "null")) {
            val = atoi(argv[i]);
            n = new TreeNode(val);
            prev->left = n;
            queue.push_back(n);
        }

        if (i == argc - 1)
            break;

        if (strcmp(argv[i+1], "null")) {
            val = atoi(argv[i+1]);
            n = new TreeNode(val);
            prev->right = n;
            queue.push_back(n);
        }
    }

    ans = solution.levelOrderBottom(root);

    for (auto &aa : ans) {
        for (auto a : aa)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
