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
    struct node {
        TreeNode *n;
        int x;
        node(TreeNode *_n, int _x) : n(_n), x(_x) {};
    };

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<node> q;
        unordered_map<int, vector<int>> map;
        int min_x = 0, max_x = 0;

        q.push({root, 0});
        while (q.size()) {
            int q_sz = q.size();
            unordered_map<int, vector<int>> _map;

            for (int i = 0; i < q_sz; i ++) {
                struct node nn = q.front();
                q.pop();

                _map[nn.x].push_back(nn.n->val);

                if (nn.n->left) {
                    q.push({nn.n->left, nn.x-1});
                    min_x = min(min_x, nn.x-1);
                }
                if (nn.n->right) {
                    q.push({nn.n->right, nn.x+1});
                    max_x = max(max_x, nn.x+1);
                }
            }

            for (auto &ele : _map) {
                sort(ele.second.begin(), ele.second.end());
                map[ele.first].insert(map[ele.first].end(), ele.second.begin(), ele.second.end());
            }
        }

        for (int i = min_x; i <= max_x; i ++) {
            ans.push_back(map[i]);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    TreeNode *root = new TreeNode(atoi(argv[1]));
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    int n;

    q.push(root);
    for (int i = 2; i < argc; i ++) {
        TreeNode *p = q.front();
        q.pop();

        n = atoi(argv[i]);
        if (n >= 0) {
            p->left = new TreeNode(atoi(argv[i]));
            q.push(p->left);
        }

        if (++ i >= argc)
            break;

        n = atoi(argv[i]);
        if (n >= 0) {
            p->right = new TreeNode(atoi(argv[i]));
            q.push(p->right);
        }
    }

    ans = solution.verticalTraversal(root);

    for (auto &an : ans) {
        for (auto a : an) {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
