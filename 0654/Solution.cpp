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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode *> stack;

        for (auto n : nums) {
            TreeNode *node = new TreeNode(n);
            while (stack.size() && stack.back()->val < n) {
                node->left = stack.back();
                stack.pop_back();
            }
            if (stack.size())
                stack.back()->right = node;
            stack.push_back(node);
        }

        return stack.size() ? stack[0] : nullptr;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> nums;
    TreeNode *root;
    queue<TreeNode *> queue;

    for (int i = 1; i < argc; i ++) {
        int n = atoi(argv[i]);
        nums.push_back(n);
    }

    root = solution.constructMaximumBinaryTree(nums);

    queue.push(root);
    while (queue.size()) {
        int sz = queue.size();
        for (int i = 0; i < sz; i ++) {
            TreeNode *n = queue.front();
            queue.pop();

            if (n) {
                cout << n->val << " ";
                queue.push(n->left);
                queue.push(n->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }

    return 0;
}
