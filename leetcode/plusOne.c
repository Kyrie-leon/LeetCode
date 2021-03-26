
int* plusOne(int* digits, int digitsSize, int* returnSize){
    
    //开辟数组比原数组+1
    int* retArr = (int *)malloc(sizeof(int)*(digitsSize+1));
    int bit = 0;
    //先给数+1，如果没有进位直接返回，否则进位+1
    if(digits[digitsSize-1] + 1 < 10)
    {
        digits[digitsSize-1] = digits[digitsSize-1] + 1;
        *returnSize = digitsSize;
        return digits;
    }
    else
    {
        bit = 1;
        retArr[digitsSize] = (digits[digitsSize-1] + 1)%10;
    }
    //有进位，逐个元素赋值到retArr
    for(int i = digitsSize - 2; i >= 0; --i)
    {
        //小于10进位置0
        if(digits[i] + bit < 10)
        {
            retArr[i+1] = digits[i] + bit;
            bit = 0;
        }
        //大于10进位置1
        else
        {
            retArr[i+1] = (digits[i] + bit)%10;
            bit = 1;
        }
    }
    //最高位有进位，最高位置1
    if(bit)
    {
        retArr[0] = bit;
        *returnSize = digitsSize+1;
        return retArr;
    }
    else
    {
        *returnSize = digitsSize;
        return retArr+1;
    }
}