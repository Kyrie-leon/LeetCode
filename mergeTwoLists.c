/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    /***************思路***********
    首先确定新链表的头节点，然后定义两个指针比较两个链表的val依次链接
    ******************************/
    //1.两个链表都为空
    if(l1==NULL && l2==NULL)
    {
        return NULL;
    }
    //2.一个为空一个不为空
    else if(l1==NULL)
    {
        return l2;
    }
    else if(l2==NULL)
    {
        return l1;
    }
    else
    {
        //默认l1为头节点
        ListNode * newHead= (ListNode *)malloc(sizeof(ListNode));    //定义一个哨兵节点
        newHead->next = NULL;
        ListNode * cur = newHead;
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                cur->next = l1;
                l1=l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
        }
        //谁长链接谁
        if(l1==NULL)
        {
            cur->next=l2;
        }
        else if(l2==NULL)
        {
            cur->next=l1;
        }
        return newHead->next;

    }
}
