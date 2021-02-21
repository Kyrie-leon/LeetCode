/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool IsEvenNum(int num)
{
    return num%2 == 0 ? true : false;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    //双指针交换
    int left = 0;
    int right = ASize - 1;
    while(left <= right)
    {
        if(!IsEvenNum(A[left]) && IsEvenNum(A[right]))
        {
            int tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;
            ++left; 
            --right;
        }
        else if(IsEvenNum(A[left]))
        {
            ++left;            
        }
        else
        {
            --right;
        }
    }

    *returnSize = ASize;
    return A;

}