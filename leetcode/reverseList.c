/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head){
    /* 思路2 递归*/
    if (NULL==head || NULL == head->next)
    {
        return head;
    }

    Node * ret=reverseList(head->next);    //迭代
    head->next->next = head;
    head->next=NULL;
    return ret;


    /*  思路1 迭代法
    if(NULL == head)
    {
        return head;
    }

    写法2
    Node * prev=NULL;
    Node * cur=head;
    while(cur!=NULL)
    {
        Node * next=cur->next; //每次循环定义next指向cur后的一个节点
        cur->next=prev; //当前节点指向前一个节点
        prev=cur;   //prev后移
        cur=next;   //cur后移
    }


    写法1
    Node * prev=NULL;
    Node * cur=head;
    Node * next=head->next;    
    while(cur!=NULL)
    {
        
        cur->next=prev; //当前节点指向前一个节点
        prev=cur;   //prev后移
        cur=next;   //cur后移

        //1.next不为空时继续后移
        if(next) 
        {
            next=next->next;
        }
    }

    return prev;
    */
}