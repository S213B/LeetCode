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

class BSTIterator {
private:
    queue<int> q;

    void preorder(TreeNode *node) {
        if (!node)
            return;
        preorder(node->left);
        q.push(node->val);
        preorder(node->right);
    }

public:
    BSTIterator(TreeNode *root) {
        preorder(root);
    }

    int next(void) {
        int n = q.front();
        q.pop();
        return n;
    }

    bool hasNext(void) {
        return !q.empty();
    }
};

int main(int argc, char *argv[]) {
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(atoi(argv[1]));

    q.push(root);
    for (int i = 2; i < argc; i ++) {
        TreeNode *father = q.front();
        q.pop();

        if (strcmp(argv[i], "null")) {
            int n = atoi(argv[i]);
            TreeNode *child = new TreeNode(n);
            q.push(child);
            father->left = child;
        }

        if (++i >= argc)
            break;

        if (strcmp(argv[i], "null")) {
            int n = atoi(argv[i]);
            TreeNode *child = new TreeNode(n);
            q.push(child);
            father->right = child;
        }
    }

    BSTIterator it(root);

    while (it.hasNext())
        cout << it.next() << " ";
    cout << endl;

    return 0;
}
