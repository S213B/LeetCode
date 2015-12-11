/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int x = p->val, y = q->val, t;
    while(true) {
        t = root->val;
        if(t > x && t > y) {
            root = root->left;
        } else if(t < x && t < y) {
            root = root->right;
        } else {
            return root;
        }
    }
}
