/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == p || root == q) {
        return root;
    }
    
    struct TreeNode* left = NULL;
    struct TreeNode* right = NULL;
    
    if(root->left != NULL) {
        left = lowestCommonAncestor(root->left, p, q);
        if(left != NULL && left != p && left != q) {
            return left;
        }
    }
    
    if(root->right != NULL) {
        right = lowestCommonAncestor(root->right, p, q);
        if(right != NULL && right != p && right != q) {
            return right;
        }
    }
    
    if(left != NULL && right != NULL) {
        return root;
    } else if(left != NULL) {
        return left;
    } else if(right != NULL) {
        return right;
    } else {
        return NULL;
    }
    
}
