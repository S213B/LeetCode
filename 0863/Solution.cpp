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
private:
    int _distanceK(TreeNode *n, TreeNode *target, int K, int dis, vector<int> &ans) {
        if (!n)
            return -1;

        if (n == target)
            dis = 0;

        if (dis == K)
            ans.push_back(n->val);

        if (n == target || dis >= 0) {
            _distanceK(n->left, target, K, dis+1, ans);
            _distanceK(n->right, target, K, dis+1, ans);
            return (n == target) ? 1 : -1;
        }

        int left_dis, right_dis;

        left_dis = _distanceK(n->left, target, K, dis, ans);
        right_dis = _distanceK(n->right, target, K, dis, ans);

        if (right_dis >= 0) {
            _distanceK(n->left, target, K, right_dis + 1, ans);
            dis = right_dis + 1;
        }
        if (left_dis >= 0) {
            _distanceK(n->right, target, K, left_dis + 1, ans);
            dis = left_dis + 1;
        }

        if (right_dis == K || left_dis == K)
            ans.push_back(n->val);

        return dis;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;

        _distanceK(root, target, K, -1, ans);

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    int K = atoi(argv[1]);
    int v = atoi(argv[2]);
    TreeNode *root = new TreeNode(atoi(argv[3]));
    TreeNode *target;
    queue<TreeNode *> q;
    vector<int> ans;

    q.push(root);
    for (int i = 4; i < argc; i ++) {
        TreeNode *p = q.front();
        q.pop();

        if (strcmp(argv[i], "null")) {
            TreeNode *n = new TreeNode(atoi(argv[i]));
            if (n->val == v)
                target = n;
            q.push(n);
            p->left = n;
        }

        if (++i >= argc)
            break;

        if (strcmp(argv[i], "null")) {
            TreeNode *n = new TreeNode(atoi(argv[i]));
            if (n->val == v)
                target = n;
            q.push(n);
            p->right = n;
        }
    }

    ans = solution.distanceK(root, target, K);

    for (auto n : ans)
        cout << n << " ";
    cout << endl;

    return 0;
}
