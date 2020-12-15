#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//逆置数组
void reverse(int * arr, int size, int start, int end)
{
	while (start>end)
	{
		swap(&arr[start], &arr[end - 1]);
		start++;
		end++;
	}
}



/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	//1.计算K的位数
	int KSize = 0;    //K的位数也是K数组的大小
	int tmp = K;
	while (tmp)
	{
		tmp = tmp / 10;
		KSize++;
	}

	tmp = K;
	int * karr = (int *)malloc(sizeof(int)*KSize);

	int ansSize = ASize>KSize ? ASize + 1 : KSize + 1;      //最后的结果数组长度不会超过最大数组长度+1的长度
	int * ans = (int *)malloc(sizeof(int)*ansSize);
	//2.将K存入数组karr
	while (KSize)
	{
		*karr = tmp % 10;
		karr++;
		tmp /= 10;
		KSize--;
	}
	//3.将A和K数组都按左边最小位逆置
	reverse(A, ASize, 0, ASize - 1);
	//4.A和K相加的结果存入ans,
	int Adig = 0, Kdig = 0, flag = 0, i = 0;
	for (i = 0; i<ansSize; i++)
	{
		Adig = i>ASize ? 0 : A[i];
		Kdig = i>KSize ? 0 : karr[i];
		ans[i] = (Adig + Kdig + flag) % 10;
		flag = (Adig + Kdig + flag) / 10;
	}
	if (flag == 1)
	{
		ans[i] = 1;
		i++;
	}
	//5.将ans逆置输出
	reverse(ans, i, 0, i - 1);
	*returnSize = i;
	return ans;


}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//逆置数组
void reverse(int * arr, int size, int start, int end)
{
	while (start<end)
	{
		swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}



/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	//1.计算K的位数
	int KSize = 0;    //K的位数也是K数组的大小
	int Knum = K;
	while (Knum)
	{
		Knum /= 10;
		KSize++;
	}

	int ansSize = ASize>KSize ? ASize : KSize;      //最后的结果数组长度不会超过最大数组长度+1的长度
	int * ans = (int *)malloc(sizeof(int)*(ansSize + 1));
	
    //2.A和K相加的结果存入ans,
	int nextnum=0;  //代表下一位的进位的值0或1
    int Ai=ASize-1;   //表示Ai的每一位
    int ansi=0;
    int a=0;
    //将A和K的结果相加
    while(ansSize--)
    {
        //确保A数组不越界
        if(Ai>=0)
        {
            a = A[Ai];
            Ai--;
        }

        int ret = a + K%10+nextnum;     //每一位的结果为a数组每一位+K的每一位+进位
        K /=10;
        //如果结果大于10表示有进位
        if(ret>9)
        {
            ret -= 10;
            nextnum=1;
        }
        else
        {
            nextnum=0;
        }
        ans[ansi]=ret;
        ansi++;
    }
    // if (nextnum == 1)
	// {
	// 	ans[ansi] = 1;
	// 	ansi++;
	// }
	//5.将ans逆置输出
	reverse(ans, ansi, 0, ansi - 1);
	*returnSize = ansi;
	return ans;


}

int main()
{
	int K = 34;
	int A[4] = { 1,2,0,0 };
	addToArrayForm(A, 4, K, NULL);
	return 0;
}
