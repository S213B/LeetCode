#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return nullptr;

        int mid = preorder[0], idx = 0;
        while (inorder[idx] != mid) idx ++;

        vector<int> pre_left(preorder.begin() + 1, preorder.begin() + 1 + idx);
        vector<int> pre_right(preorder.begin() + 1 + idx, preorder.end());

        vector<int> in_left(inorder.begin(), inorder.begin() + idx);
        vector<int> in_right(inorder.begin() + idx + 1, inorder.end());

        TreeNode *n = new TreeNode(mid);
        n->left = buildTree(pre_left, in_left);
        n->right = buildTree(pre_right, in_right);

        return n;
    }
};

static void
go_preorder(TreeNode *n, vector<int> &v) {
    if (!n)
        return;
    v.push_back(n->val);
    go_preorder(n->left, v);
    go_preorder(n->right, v);
}

static void
go_inorder(TreeNode *n, vector<int> &v) {
    if (!n)
        return;
    go_inorder(n->left, v);
    v.push_back(n->val);
    go_inorder(n->right, v);
}

static bool
compare_tree(TreeNode *n1, TreeNode *n2) {
    if (!n1 && !n2)
        return true;
    if (!n1 || !n2)
        return false;
    if (n1->val != n2->val)
        return false;
    return compare_tree(n1->left, n2->left) &&
           compare_tree(n1->right, n2->right);
}

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> preorder, inorder;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(atoi(argv[1]));
    TreeNode *ans;

    q.push(root);
    for (int i = 2; i < argc; i ++) {
        TreeNode *father = q.front();
        q.pop();

        if (strcmp(argv[i], "null")) {
            TreeNode *child = new TreeNode(atoi(argv[i]));
            q.push(child);
            father->left = child;
        }

        if (++i >= argc)
            break;


        if (strcmp(argv[i], "null")) {
            TreeNode *child = new TreeNode(atoi(argv[i]));
            q.push(child);
            father->right = child;
        }
    }

    go_preorder(root, preorder);
    go_inorder(root, inorder);

    ans = solution.buildTree(preorder, inorder);

    cout << compare_tree(root, ans) << endl;

    return 0;
}
