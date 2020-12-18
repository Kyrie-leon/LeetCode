#include<stdio.h>
#include<stdlib.h>

//Method 1
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//1.将nums2存入到nums1中
	for (int i = m, j = 0; i<m + n; i++, j++)
	{
		nums1[i] = nums2[j];  //nums2从第一个有效数字开始依次拷贝到nums1的最后一个有效数字后面
	}
	//2.对nums1排序,冒泡排序
	for (int i = 0; i<m + n - 1; i++)  //
	{
		for (int j = 0; j<m + n - i - 1; j++)
		{
			if (nums1[j]>nums1[j + 1])
			{
				int temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int nums1[6] = { 4,5,6,0,0,0 };
	int nums2[3] = { 1,2,3 };
	merge(nums1, 6, 3, nums2, 3, 3);
}