/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//求出树中节点的个数
int TreeSize(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return 1+TreeSize(root->left)+TreeSize(root->right);
}

//二叉树前序遍历
void PrevOrder(struct TreeNode* root, int* retArr, int* i)
{
    if(root==NULL)
        return;
    retArr[(*i)++]=root->val;
    PrevOrder(root->left,retArr,i);
    PrevOrder(root->right,retArr,i);
    
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int* retArr = (int *)malloc(sizeof(int)*size);
    int i = 0;
    PrevOrder(root, retArr, &i);
    *returnSize = size;
    return retArr;
}