char* replaceSpace(char* s){
    int numSize = strlen(s);
    char* ret = (char *)malloc(sizeof(char)*3*numSize+1);
    int i = 0;
    int j = 0;
    while(s[j])
    {
        if(s[j] == ' ')
        {
            ret[i++] = '%';
            ret[i++] = '2';
            ret[i++] = '0';
        }
        else
        {
            ret[i++] = s[j];
        }
        ++j;
    }
    ret[i] = '\0';
    return ret;
}