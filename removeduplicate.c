#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {


	//1.�����жϴ��������Ƿ�Ϊ�ջ򵥸�Ԫ��
	if (numsSize - 1 <= 0)
	{
		return numsSize;
	}


	//2.����˫ָ��
	int pre = 0;
	int cur = 1;


	// while(cur<numsSize)
	// {
	//     //Ԫ����ȣ�cur+1
	//     if(nums[pre]==nums[cur])
	//     {
	//         ++cur;
	//     }
	//     //����
	//     else
	//     {
	//         ++pre;
	//         nums[pre]=nums[cur];
	//         ++cur;
	//     }
	// }
	while (cur<numsSize)
	{
		//�����ʱ��дԪ��
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
