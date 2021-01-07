typedef char STDataType;

//支持动态增长的栈
typedef struct Stack
{
	STDataType * _a;
	int _top;			//栈顶
	int _capacity;		//容量
}Stack;

//栈的初始化
void StackInit(Stack * ps)
{
	assert(ps);
	ps->_a = (STDataType *)malloc(sizeof(Stack) * 4);	//默认数组大小为4
	ps->_top = 0;		//栈为空，则栈顶为0
	ps->_capacity = 4;	//默认栈的容量为4
}

//入栈
void StackPush(Stack * ps, STDataType data)
{
	assert(ps);
	//判断栈是否满了，满了则增容
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity *= 2;	//每次扩容2倍
		STDataType * tmp = (STDataType *)realloc(ps->_a, sizeof(Stack)*ps->_capacity);
		//判断内存是否申请成功
		if (NULL == tmp)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		ps->_a = tmp;
	}
	//入栈
	ps->_a[ps->_top] = data;	
	ps->_top++;
}

//出栈
void StackPop(Stack * ps)
{
	assert(ps);
	assert(ps->_top>0);
	ps->_top--;
}

//获取栈顶元素
STDataType StackTop(Stack *ps)
{
	assert(ps);
	assert(ps->_top>0);

	return ps->_a[ps->_top-1];	
}

//检测栈是否为空，如果为空返回非0，不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return !(ps->_top);
}

//销毁栈
void StackDestory(Stack * ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

bool isValid(char * s){

    //让字符串依次入栈，当检测到右括号时出栈
    Stack st;    //定义一个栈
    StackInit(&st);
    //遍历字符串
    while(*s)
    {
        //检测字符是否为右括号，如果是进行括号匹配
        if(')'==*s)
        {
            //如果栈非空则匹配栈顶字符
            if(!StackEmpty(&st))
            {
                //如果匹配则出栈
                if(StackTop(&st) == '(')
                {
                    StackPop(&st);
                }
                //不匹配直接返回false
                else
                {
                    return false;                   
                }
            }
            else
            {
                return false;
            }
        }
        else if('}'==*s)
        {
            //如果栈非空则匹配栈顶字符
            if(!StackEmpty(&st))
            {
                //如果匹配则出栈
                if(StackTop(&st) == '{')
                {
                    StackPop(&st);
                }
                //不匹配直接返回false
                else
                {
                    return false;                   
                }
            }
            else
            {
                return false;
            }
        }
        else if(']'==*s)
        {
            //如果栈非空则匹配栈顶字符
            if(!StackEmpty(&st))
            {
                //如果匹配则出栈
                if(StackTop(&st) == '[')
                {
                    StackPop(&st);
                }
                //不匹配直接返回false
                else
                {
                    return false;                   
                }
            }
            else
            {
                return false;
            }
        }
        //如果不是右括号字符则入栈
        else
        {
            StackPush(&st, *s);
        }
        //字符指针右移
        s++;
    }
    
    return StackEmpty(&st);

}
