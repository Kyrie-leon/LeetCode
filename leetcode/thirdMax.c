//不排序，维护三个变量first,second，third,O(n)
int thirdMax(int* nums, int numsSize){
    //维护前三大的数字，通过long型数据的最小值来判断是否有第三大的值
    long first=LONG_MIN, second=LONG_MIN, third=LONG_MIN;
    for(int i = 0; i < numsSize; ++i)
    {
        //nums[i]最大
        if(nums[i]>first)
        {
            third = second;
            second = first;
            first = nums[i];
        }
        //nums[i]次大
        if(nums[i] > second && nums[i] < first)
        {
            third = second;
            second = nums[i];
        }
        //nums[i]三大
        if(nums[i] > third && nums[i] < second)
        {
            third = nums[i];
        }
    }

    if(third == LONG_MIN)
    {
        return first;
    }

    return third;
}

