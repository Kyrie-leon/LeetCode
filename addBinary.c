//规律：'0' - '0' = 0, '1' - '0' = 1,
char * addBinary(char * a, char * b){
    //求出a，b,retArr长度
    int a_len = strlen(a);
    int b_len = strlen(b);
    int retSize = a_len > b_len? a_len + 2:b_len + 2;
    char* retArr = (char *)malloc(sizeof(char)*retSize);
    memset(retArr, '\0', retSize);
    int carry = 0;
    int i = a_len - 1;
    int j = b_len - 1;
    int k = retSize - 2;   //数组最后一个位置存放'\0'
    while(i >= 0 || j >= 0)
    {
        //短字符串补0,计算该位置的值
        int sum = carry;
        sum += (i >=0 ? a[i] - '0' : 0);
        sum += (j >= 0 ? b[j] - '0' : 0);
        
        carry = sum/2;
        retArr[k--] = '0' + (sum % 2);
        --i;
        --j;
    }
    //有进位
    if(carry)
    {
        retArr[0] = '1';
        return retArr;
    }

    return retArr + 1;       
}