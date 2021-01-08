typedef int QDataType;

//队列的链表
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

//队列的结构
typedef struct Queue
{
	QNode *_front;	//队头
	QNode *_rear;	//队尾
}Queue;


// 初始化队列 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;	//队头队尾置空即可

}
// 队尾入队列 
void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QNode * newNode = (QNode *)malloc(sizeof(QNode));	//向内存申请一个结点
	//判断是否申请成功
	if (NULL == newNode)
	{
		printf("申请失败!\n");
		exit(-1);
	}
	//将新节点入到队尾
	newNode->_data = data;	//数据data赋值给新节点	
	newNode->_next = NULL;	//新节点会作为队尾节点，因此对新节点_next置空
	
	if (pq->_front)
	{
		pq->_rear->_next = newNode;		//队列不为空，队尾结点先链接新结点
		pq->_rear = newNode;	//再将队尾指向新节点	
	}
	else
	{
		pq->_front = pq->_rear = newNode;	//如果队列为空，则队头队尾都指向新节点
	}
}

// 队头出队列 
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_front);	//出队列判断队列是否为空
	QNode* next = pq->_front->_next;	//next保存新队头结点
	free(pq->_front);
	pq->_front = next;
	//出队列后需要判断队列是否为空
	if (NULL == pq->_front)
	{
		pq->_rear = NULL;	//如果为空，则队尾也为空
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_front);
	return pq->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_rear);
	return pq->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->_front;
	//遍历一遍链表
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL ? 1 : 0;
}
// 销毁队列 
void QueueDestroy(Queue* pq)
{
	assert(pq);
	//从头节点开始遍历每一个节点并free
	QNode* cur = pq->_front;
	while (cur)
	{
		QNode* next = cur->_next;	//cur指向下一个节点
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}

//定义两个队列实现栈
typedef struct {
   Queue _q1;
   Queue _q2; 
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* st =(MyStack *)malloc(sizeof(MyStack));
    QueueInit(&st->_q1);
    QueueInit(&st->_q2);
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    //谁空入谁
    if(!QueueEmpty(&obj->_q1))
    {
        QueuePush(&obj->_q1,x);
    }
    else
    {
        QueuePush(&obj->_q2,x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {

    //默认q1为空，q2不为空
    Queue* empty = &obj->_q1;    //error1:此处为指针应该取地址
    Queue* noneEmpty = &obj->_q2;
    if(QueueEmpty(&obj->_q2))
    {
        empty = &obj->_q2;
        noneEmpty = &obj->_q1;
    }

    //将非空队列除队尾元素外依次入队空队列
    while(QueueSize(noneEmpty)>1)
    {
        QueuePush(empty,QueueFront(noneEmpty)); //非空入队空队列 error2:参数二应传非空队列的队头元素
        QueuePop(noneEmpty);   //非空出队
    }

    int top = QueueBack(noneEmpty);    //获取队尾元素，即栈顶元素做返回值
    QueuePop(noneEmpty);
    return top;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {

    if(!QueueEmpty(&obj->_q1))
    {
        return QueueBack(&obj->_q1);
    }
    else
    {
        return QueueBack(&obj->_q2);
    }
    
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->_q1);
    QueueDestroy(&obj->_q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/