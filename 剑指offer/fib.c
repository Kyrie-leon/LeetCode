//迭代实现
int fib(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;

    int n_1 = 1;
    int n_2 = 1;
    int ret = 0;
    for(int i = 3; i <= n; ++i)
    {
        ret = n_1 + n_2;
        ret %= 1000000007;
        n_2 = n_1;
        n_1 = ret;
    }

    return ret;
}