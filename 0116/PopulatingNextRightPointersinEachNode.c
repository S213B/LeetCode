/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(root == NULL || root->left == NULL) {
        return;
    }
    root->left->next = root->right;
    if(root->next != NULL) {
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
}
