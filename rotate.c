//方法1，数组逐步往后挪，空间复杂度O(1),时间复杂度O(kN),过不了OJ
void rotate1(int* nums, int numsSize, int k){
    if(!nums || k%numsSize == 0)
        return;
    
    int step = k%numsSize;
    for(; step > 0; --step)
    {
        int length = numsSize-1;
        int tmp = nums[length];
        while(length)
        {
            nums[length] = nums[length-1];
            --length;
        }
        nums[0] = tmp;
    }
}

void reverse(int* nums, int numsSize, int left, int right){
    while(left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        ++left;
        --right;
    }
}

//方法2，先整体逆置，再分别逆置,空间复杂度O(1),时间复杂度O(2N)
void rotate2(int* nums, int numsSize, int k){
    if(!nums || k%numsSize == 0)
        return;
    
    int step = k%numsSize;
    //1234567->7654321
    reverse(nums, numsSize, 0, numsSize-1);
    //765->567，4321->1234
    reverse(nums, numsSize, 0, step-1);
    reverse(nums, numsSize, step, numsSize-1);
}

//方法3.先分开逆置最后整体逆置和方法2一样
void rotate3(int* nums, int numsSize, int k){
    if(!nums || k%numsSize == 0)
        return;
    
    int step = k%numsSize;
    //1234->4321  567->765
    reverse(nums, numsSize, 0, numsSize-step-1);
    reverse(nums, numsSize, numsSize-step, numsSize-1);
    //4321765->5674321
    reverse(nums, numsSize, 0, numsSize-1);
}

void rotate(int* nums, int numsSize, int k){
    rotate3(nums, numsSize, k);
}