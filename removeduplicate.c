#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {


	//1.首先判断传入数组是否为空或单个元素
	if (numsSize - 1 <= 0)
	{
		return numsSize;
	}


	//2.定义双指针
	int pre = 0;
	int cur = 1;


	// while(cur<numsSize)
	// {
	//     //元素相等，cur+1
	//     if(nums[pre]==nums[cur])
	//     {
	//         ++cur;
	//     }
	//     //不等
	//     else
	//     {
	//         ++pre;
	//         nums[pre]=nums[cur];
	//         ++cur;
	//     }
	// }
	while (cur<numsSize)
	{
		//不相等时复写元素
		if (nums[cur] != nums[pre])
		{
			nums[++pre] = nums[cur];
		}
		cur++;
	}


	return ++pre;


}

int main()
{
	int nums[10] = { 0,0,1,1,1,2,2,3,3,4 };
	int ret = removeDuplicates(nums, 10);
	for (int i = 0; i < ret; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}
