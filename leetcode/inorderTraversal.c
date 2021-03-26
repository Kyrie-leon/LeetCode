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
//二叉树的后序遍历
void InOrder(struct TreeNode* root, int* arr, int* i)
{
    if(root==NULL)
        return ;
    InOrder(root->left, arr,i);
    arr[(*i)++]=root->val;
    InOrder(root->right,arr,i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);  //求出数组大小
    int* arr = (int *)malloc(sizeof(int)*size);
    int i = 0;
    InOrder(root, arr, &i);
    *returnSize = size;
    return arr;
}