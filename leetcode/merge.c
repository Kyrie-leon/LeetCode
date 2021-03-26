#include<stdio.h>
#include<stdlib.h>

//Method 1时间复杂度O(m+n)^2效率低
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

//时间复杂度O(m+n),空间复杂度O(1)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //三个指针分别指向数组末尾
    int p1 = m-1;
    int p2 = n-1;
    int p = m+n-1;
    while(p1 >= 0 && p2 >= 0)
    {
        nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
    }
	//数组2漏存的数字全部填入
    while(p2 >= 0)
        nums1[p--] = nums2[p2--];
}