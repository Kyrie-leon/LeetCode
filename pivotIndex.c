//先计算数组值之和为sum，假设第i个元素的值为numsi,其左侧值之和为preSum，那么右侧之和为sum-preSum-numsi
//左右之和相等preSum == sum-preSum-numsi
//2preSum + numsi == sum

int pivotIndex(int* nums, int numsSize){
    //第一遍求和
    int sum = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
    }
    //第二遍找索引值
    int preSum = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(2*preSum + nums[i] == sum)
        {
            return i;
        }
        preSum += nums[i];
    }

    return -1;
}