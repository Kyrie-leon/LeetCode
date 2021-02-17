
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
    if(target < nums[0])
    {
        return 0;
    }
    else
    {
        return insert + 1;
    }
}

//二分法
int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(target < nums[mid])
        {
            right = mid-1;
        }
        else if(target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return left;
}