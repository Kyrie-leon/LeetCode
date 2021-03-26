bool isLongPressedName(char * name, char * typed){
    int nameLen = strlen(name);
    int typedLen = strlen(typed);
    int i = 0,j = 0;
    //双指针判断
    while(i < nameLen && j < typedLen)
    {
        //字符相等，指针同时移动
        if(name[i] == typed[j])
        {
            ++i;
            ++j;
        }
        else
        {   
            //第一位不相等直接返回false
            if(j == 0)
            {
                return false;
            }
            //如果字符重复移动到不重复的字符
            while(typed[j-1] == typed[j]) 
            {
                ++j;
            }

            //字符不等返回false
            if(name[i] != typed[j])
            {
                return false;
            }
        }
    }

    //name字符未遍历完直接返回false
    if(i < nameLen)
        return false;

    //typed字符如果是相同的字符返回true，不相同返回false
    while(j < typedLen)
    {
       if(typed[j-1] == typed[j])
        {
            ++j;
        }
        else
        {
            return false;
        }
    }

    return true;
}