typedef int STDataType;
typedef struct Stack Stack;

//支持动态增长的栈
struct Stack
{
	STDataType * _a;
	int _top;			//栈顶
	int _capacity;		//容量
};

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

//获取栈中有效元素个数
int StackSize(Stack * ps)
{
	assert(ps);
	return ps->_top;
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

typedef struct {
    Stack _pushSt;  //队列入栈
    Stack _popSt;   //队列出栈
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue *)malloc(sizeof(MyQueue));
    StackInit(&q->_pushSt);
    StackInit(&q->_popSt);

    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    //元素直接入栈_pushSt
    StackPush(&obj->_pushSt,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    //1.如果popSt不为空，直接出栈顶元素即可
    if(!StackEmpty(&obj->_popSt))
    {
        int front = StackTop(&obj->_popSt); //front保存栈顶元素即队头用于返回
        StackPop(&obj->_popSt);
        return front;
    }
    else
    {
        //pushSt非空依次入栈popSt
        while(!StackEmpty(&obj->_pushSt))
        {
            StackPush(&obj->_popSt,StackTop(&obj->_pushSt));    //pushSt栈顶元素依次入栈popSt
            StackPop(&obj->_pushSt); //pushSt栈顶出栈
        }
        int front = StackTop(&obj->_popSt); //front保存栈顶元素即队头用于返回
        StackPop(&obj->_popSt);
        return front;
    }
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
        //1.如果popSt不为空，直接出栈顶元素即可
    if(!StackEmpty(&obj->_popSt))
    {
        return StackTop(&obj->_popSt);
    }
    else
    {
        //pushSt非空依次入栈popSt
        while(!StackEmpty(&obj->_pushSt))
        {
            StackPush(&obj->_popSt,StackTop(&obj->_pushSt));    //pushSt栈顶元素依次入栈popSt
            StackPop(&obj->_pushSt); //pushSt栈顶出栈
        }
        return StackTop(&obj->_popSt);
    }
    
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->_pushSt) && StackEmpty(&obj->_popSt);
}

void myQueueFree(MyQueue* obj) {

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/