int searchInsert(int* nums, int numsSize, int target){
    int insert = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == target)
        {
            return i;
        }
        if(target > nums[i])
        {
            insert = i;
        }
    }

        return insert+1;
}