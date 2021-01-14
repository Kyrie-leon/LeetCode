/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    //只需求出根节点的左右孩子最大深度
    if(root == NULL)
        return 0;
    return 1+fmax(maxDepth(root->left),maxDepth(root->right));
}