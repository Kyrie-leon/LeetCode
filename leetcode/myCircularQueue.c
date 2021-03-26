typedef struct {
    int *_a;    //数组
    int _front; //队头
    int _rear;  //队尾
    int _k;     //队列容量

} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cq = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    cq->_a = (int *)malloc(sizeof(int)*(k+1));  //error1:要给数组开辟空间
    cq->_front = 0;
    cq->_rear = 0;
    cq->_k = k+1;

    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //队列不满
    if(!myCircularQueueIsFull(obj))
    {
        obj->_a[obj->_rear] = value;
        obj->_rear++;
        obj->_rear %=obj->_k; //error2:当rear在数组中越界时要合法
        return true;
    }
    else
    {
        return false;
    }

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!myCircularQueueIsEmpty(obj))
    {

        obj->_front++;
        obj->_front %= obj->_k;
        return true;
    }
    else
    {
        return false;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        return obj->_a[obj->_front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        int tail = obj->_rear-1; 
        if(tail == -1)
        {
            tail = obj->_k-1;
        } 
        return obj->_a[tail];
    }

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->_rear+1)%obj->_k == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/