/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    /***********思想
    *****遍历链表A、B，算出长度numA和numB，求出差值n，让最长的链表先走n步，然后两个链 表同时走
    当两个链表节点的地址相等时，代表找到了相交点
    */
    int numA=0;
    int numB=0;

    ListNode * Acur=headA;
    ListNode * Bcur=headB;
    //遍历A链表节点计算长度
    while(Acur)
    {
        Acur = Acur->next;
        ++numA;
    }
    //遍历B链表节点计算长度
    while(Bcur)
    {
        Bcur = Bcur->next;
        ++numB;
    }
    
    Acur=headA;
    Bcur=headB;
    int n =abs(numA-numB);
    //那个链表长就让哪个链表先走n步
    if(numA>numB)
    {   
        while(n--)
        {
            Acur = Acur->next;
        }
    }
    else if(numA<numB)
    {
        while(n--)
        {
            Bcur = Bcur->next;
        }
    }
    //对其以后，同时遍历就可以找到相交点
    while(Acur != NULL)
    {
        if(Acur==Bcur)
        {
            return Acur;
        }
        Acur = Acur->next;
        Bcur = Bcur->next;
    }

    return NULL;
}
