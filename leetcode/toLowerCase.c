//调用库函数
char * toLowerCase1(char * str){
    char *dst = str;
    int length = strlen(str);
    for(int i = 0;i < length; ++i)
    {   
        if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    } 

    return dst;
}

//不调用库函数
char * toLowerCase(char * str){
    char *dst = str;
    int length = strlen(str);
    for(int i = 0;i < length; ++i)
    {   
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    } 

    return dst;
}