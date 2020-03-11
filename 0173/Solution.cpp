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

#define ITERATION

#ifdef ITERATION
// iterative preorder/inorder/postorder traversal

void preorder(TreeNode *node) {
    stack<TreeNode *> stk;
    while (node || stk.size()) {
        if (!node) {
            node = stk.top();
            stk.pop();
        }
        cout << node->val << " ";
        if (node->right)
            stk.push(node->right);
        node = node->left;
    }
    cout << endl;
}

void inorder(TreeNode *node) {
    stack<TreeNode *> stk;
#if 0
    while (node || stk.size()) {
        if (!node) {
            node = stk.top();
            stk.pop();
            cout << node->val << " ";
            node = node->right;
        }
        if (node) {
            stk.push(node);
            node = node->left;
        }
    }
#else
    while (node || stk.size()) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        cout << node->val << " ";
        node = node->right;
    }
#endif
    cout << endl;
}

void postorder(TreeNode *node) {
    stack<TreeNode *> stk;
    stack<int> ans;
    while (node || stk.size()) {
        if (!node) {
            node = stk.top();
            stk.pop();
        }
        if (node->right)
            stk.push(node->right);
        ans.push(node->val);
        node = node->left;
    }
    while (ans.size()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}
#endif

class BSTIterator {
private:
    stack<TreeNode *> stk;
    TreeNode *node;

public:
    BSTIterator(TreeNode *root) {
        node = root;
    }

    int next(void) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
        TreeNode *n = stk.top();
        stk.pop();
        node = n->right;
        return n->val;
    }

    bool hasNext(void) {
        return node || stk.size();
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

#ifdef ITERATION
    cout << "preorder:" << endl;
    preorder(root);
    cout << "inorder:" << endl;
    inorder(root);
    cout << "postorder:" << endl;
    postorder(root);
#else
    BSTIterator it(root);

    while (it.hasNext())
        cout << it.next() << " ";
    cout << endl;
#endif

    return 0;
}
