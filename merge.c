#include<stdio.h>
#include<stdlib.h>

//Method 1ʱ�临�Ӷ�O(m+n)^2Ч�ʵ�
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	//1.��nums2���뵽nums1��
	for (int i = m, j = 0; i<m + n; i++, j++)
	{
		nums1[i] = nums2[j];  //nums2�ӵ�һ����Ч���ֿ�ʼ���ο�����nums1�����һ����Ч���ֺ���
	}
	//2.��nums1����,ð������
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

//ʱ�临�Ӷ�O(m+n),�ռ临�Ӷ�O(1)
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //����ָ��ֱ�ָ������ĩβ
    int p1 = m-1;
    int p2 = n-1;
    int p = m+n-1;
    while(p1 >= 0 && p2 >= 0)
    {
        nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
    }
	//����2©�������ȫ������
    while(p2 >= 0)
        nums1[p--] = nums2[p2--];
}