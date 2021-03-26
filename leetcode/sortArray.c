/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 希尔排序
int* sortArray(int* a, int n, int* returnSize)
{
    
	//1.gap>1时为预排序，让数列更接近有序
	//2.gap=1为直接插入排序，保证有序
	int gap = n;	
	while (gap > 1)
	{
		gap = gap / 3 + 1;					//通常的
		for (int i = 0; i < n - gap; ++i)	//i从0开始到n-gap结束
		{
			int end = i;			
			int tmp = a[end + gap];			//每次增加gap的步长作为插入元素
			while (end >= 0)
			{
				if (tmp < a[end])			//如果待插入元素比end下标的元素小
				{
					a[end + gap] = a[end];	//1.end下标元素向后挪方便tmp的插入，这里end挪动的不长是gap而不是1了
					end -= gap;				//2.end左移进行下一轮的比较，同理左移gap步长
				}
				else                        //如果待插入元素大于或等于end下标的元素退出循环
				{
					break;
				}

				a[end + gap] = tmp;				//将tmp插入到数组当中
			}
		}
	}
    * returnSize = n;
    return a;
	
}

