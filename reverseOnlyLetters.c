//判断字符函数
bool IsChar(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char * reverseOnlyLetters(char * S){
    //双指针遍历交换位置
    int len = strlen(S);
    int left = 0;
    int right = len-1;
    while(left <= right)
    {
        if(IsChar(S[left]) && IsChar(S[right]))
        {
            char tmp = S[left];
            S[left] = S[right];
            S[right] = tmp;
            ++left;
            --right;
        }
        else if(!IsChar(S[left]))
        {
            ++left;
        }
        else
        {
            --right;
        }

    }

    return S;

}