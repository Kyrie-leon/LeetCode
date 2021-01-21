/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 //1.自底向上
int maxDepth(struct TreeNode* root){
    //只需求出根节点的左右孩子最大深度
    if(root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return leftDepth > rightDepth? leftDepth+1: rightDepth+1;
}
bool isBalanced(struct TreeNode* root){
    if(root == NULL)
        return true;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return abs(leftDepth-rightDepth)<=1 && isBalanced(root->left) && isBalanced(root->right);
}


//2.自顶向下
bool _isBalanced(struct TreeNode* root, int* pdepth)
{
    if(root == NULL)
    {
        *pdepth = 0;
        return true;
    }
    else
    {
        //左 右 根
        int leftdepth = 0;
        if(_isBalanced(root->left,&leftdepth)==false)
            return false;
        int rightdepth= 0;
        if(_isBalanced(root->right,&rightdepth)==false)
            return false;
        if(abs(leftdepth-rightdepth)>1)
            return false;

        *pdepth = leftdepth>rightdepth? leftdepth+1 : rightdepth+1;
        return true;
    }
}


bool isBalanced(struct TreeNode* root){
    int depth = 0;
    return _isBalanced(root,&depth);
}