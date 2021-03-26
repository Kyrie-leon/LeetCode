bool ischar(char ch)
{
    if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <='z') || (ch >='A' && ch <= 'Z'))
        return true;
    return false;
}

//双指针比较
bool isPalindrome(char * s){
    
    int len = strlen(s);
    int left = 0;
    int right = len - 1;

    //将大写字符转为小写
    for(int i = 0; i < len; ++i)
    {
        if(ischar(s[i]) && isupper(s[i]))
            s[i] = tolower(s[i]);
    }

    while(left < right)
    {
        while(!ischar(s[left]) )
            ++left;
        while(!ischar(s[right]))
            --right;
        if(s[left] != s[right])
            return false;
        ++left;
        --right;
    }

    return true;
}