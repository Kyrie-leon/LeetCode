bool isPalindrome(int x){
    if(x < 0)
        return false;
    int num = x;
    long reverNum = 0;
    while(num)
    {
        reverNum = 10*reverNum + num %10;
        num /= 10;
    }

    if(reverNum == x)
    {
        return true;
    }
    else
    {
        return false;
    }

    
}