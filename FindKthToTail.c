typedef struct ListNode Node;
// struct ListNode* FindKthToTail(struct ListNode* pListHead, int k )
// {
//     //判断链表非空
//     if(pListHead==NULL || k <=0)
//     {
//         return NULL;
//     }
    
//     //定义一个计数器用来技术链表长度
//     int count =0;
//     //遍历链表
//     Node * cur = pListHead;
//     while(cur)
//     {
//         cur=cur->next;    //cur指针右移
//         ++count;    //计数器+1
//     }
    
//     //判断k是否大于链表长度
//     if(count<k)
//     {
//         return NULL;
//     }
//     //新的头节点
//     Node * NewHead = pListHead;
//     for(int i=0;i<count-k;i++)
//     {
//         NewHead=NewHead->next;
//     }
    
//     return NewHead;
    
//  }
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    //设一个快慢指针，快指针比慢指针快n步
    if(pListHead==NULL || k<=0)
    {
        return NULL;
    }
    Node * fast =pListHead;
    
    
    //快指针先走k步
   
    while(k--)
    {
        if(fast==NULL)
            return NULL;
        fast=fast->next;
    }
    
    //慢指针开始走
    Node * slow =pListHead;
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    return slow;
    
}