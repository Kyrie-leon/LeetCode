int lengthOfLastWord(char * s){
    int len = strlen(s);
    int ret = 0;
    for(int i = len-1; i >= 0; --i)
    {
        if(s[i] == ' ' && ret > 0)
        {
            break;
        }
        if(s[i] != ' ')
        {
            ret++;
        }
    }

    return ret;

}