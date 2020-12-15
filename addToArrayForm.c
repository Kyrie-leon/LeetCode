#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//��������
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
	//1.����K��λ��
	int KSize = 0;    //K��λ��Ҳ��K����Ĵ�С
	int tmp = K;
	while (tmp)
	{
		tmp = tmp / 10;
		KSize++;
	}

	tmp = K;
	int * karr = (int *)malloc(sizeof(int)*KSize);

	int ansSize = ASize>KSize ? ASize + 1 : KSize + 1;      //���Ľ�����鳤�Ȳ��ᳬ��������鳤��+1�ĳ���
	int * ans = (int *)malloc(sizeof(int)*ansSize);
	//2.��K��������karr
	while (KSize)
	{
		*karr = tmp % 10;
		karr++;
		tmp /= 10;
		KSize--;
	}
	//3.��A��K���鶼�������Сλ����
	reverse(A, ASize, 0, ASize - 1);
	//4.A��K��ӵĽ������ans,
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
	//5.��ans�������
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

//��������
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
	//1.����K��λ��
	int KSize = 0;    //K��λ��Ҳ��K����Ĵ�С
	int Knum = K;
	while (Knum)
	{
		Knum /= 10;
		KSize++;
	}

	int ansSize = ASize>KSize ? ASize : KSize;      //���Ľ�����鳤�Ȳ��ᳬ��������鳤��+1�ĳ���
	int * ans = (int *)malloc(sizeof(int)*(ansSize + 1));
	
    //2.A��K��ӵĽ������ans,
	int nextnum=0;  //������һλ�Ľ�λ��ֵ0��1
    int Ai=ASize-1;   //��ʾAi��ÿһλ
    int ansi=0;
    int a=0;
    //��A��K�Ľ�����
    while(ansSize--)
    {
        //ȷ��A���鲻Խ��
        if(Ai>=0)
        {
            a = A[Ai];
            Ai--;
        }

        int ret = a + K%10+nextnum;     //ÿһλ�Ľ��Ϊa����ÿһλ+K��ÿһλ+��λ
        K /=10;
        //����������10��ʾ�н�λ
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
	//5.��ans�������
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
