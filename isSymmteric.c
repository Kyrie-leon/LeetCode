/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
{
    //1.左右子树为空
    if(left == NULL && right == NULL)
        return true;
    //2.左右子树有结构和值不相等，返回false
    if(!left || !right || left->val != right->val)
        return false;
    
    return left->val == right->val && _isSymmetric(left->left,right->right) && _isSymmetric(left->right,right->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
        return true;
    
    return _isSymmetric(root->left, root->right);

}