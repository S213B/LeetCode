#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> queue;
        string ans;

        if (root)
            queue.push(root);
        while (queue.size()) {
            TreeNode *n = queue.front();
            queue.pop();
            if (n) {
                ans.append(to_string(n->val));
                queue.push(n->left);
                queue.push(n->right);
            } else {
                ans.append("n");
            }
            if (queue.size())
                ans.push_back(' ');
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root;
        queue<TreeNode *> queue;
        istringstream iss(data);
        vector<string> vals(istream_iterator<string>{iss}, istream_iterator<string>());

        if (!data.size())
            return nullptr;

        root = new TreeNode(stoi(vals[0]));
        queue.push(root);

        for (int i = 1; i < vals.size(); i += 2) {
            TreeNode *left = nullptr, *right = nullptr;
            TreeNode *father = queue.front();

            queue.pop();

            if (vals[i].compare("n")) {
                left = new TreeNode(stoi(vals[i]));
                father->left = left;
                queue.push(left);
            }

            if (vals[i+1].compare("n")) {
                right = new TreeNode(stoi(vals[i+1]));
                father->right = right;
                queue.push(right);
            }
        }

        return root;
    }
};

static bool
compare_tree(TreeNode *node1, TreeNode *node2) {
    if (!node1 && !node2)
        return true;
    if (!(node1 && node2))
        return false;
    if (node1->val != node2->val)
        return false;
    return compare_tree(node1->left, node2->left) &&
           compare_tree(node1->right, node2->right);
}

int main(int argc, char *argv[]) {
    Codec codec;
    queue<TreeNode *> queue;
    TreeNode *root = nullptr;
    string ans1;
    TreeNode *ans2;

    root = new TreeNode(atoi(argv[1]));
    queue.push(root);
    for (int i = 2; i < argc; i += 2) {
        TreeNode *prev = queue.front(), *n;
        int val;

        queue.pop();

        if (strcmp(argv[i], "null")) {
            val = atoi(argv[i]);
            n = new TreeNode(val);
            prev->left = n;
            queue.push(n);
        }

        if (i == argc - 1)
            break;

        if (strcmp(argv[i+1], "null")) {
            val = atoi(argv[i+1]);
            n = new TreeNode(val);
            prev->right = n;
            queue.push(n);
        }
    }

    ans1 = codec.serialize(root);
    cout << ans1 << endl;

    ans2 = codec.deserialize(ans1);
    cout << compare_tree(root, ans2) << endl;

    return 0;
}
