#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode *> queue;
        vector<int> ans;
        TreeNode *last;

        if (!root)
            return ans;

        queue.push_back(root);
        queue.push_back(nullptr);
        while (queue.size()) {
            TreeNode *n = queue.front();
            queue.pop_front();

            if (!n) {
                ans.push_back(last->val);
                if (queue.size())
                    queue.push_back(nullptr);
                else
                    break;
            } else {
                if (n->left)
                    queue.push_back(n->left);
                if (n->right)
                    queue.push_back(n->right);
                last = n;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    deque<TreeNode *> queue;
    TreeNode *root = nullptr;
    vector<int> ans;

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

    ans = solution.rightSideView(root);

    for (auto n : ans)
        cout << n;
    cout << endl;

    return 0;
}
