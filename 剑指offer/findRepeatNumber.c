int findRepeatNumber(int* nums, int numsSize){
    //1.计数法,空间O(n)
    int ret = 0;
    int* countArr = (int *)malloc(sizeof(int)*numsSize);
    memset(countArr, 0, sizeof(int)*numsSize);
    for(int i = 0; i < numsSize; ++i)
    {
        countArr[nums[i]]++;
    }

    for(int j = 0; j < numsSize; ++j)
    {
        if(countArr[j] >=2 )
        {
            ret = j;
            break;
        }
    }
    return ret;
}
