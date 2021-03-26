/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        /*    思路
        **将小于x的节点组成一个链表，大于x的节点组成一个链表，最后将大链表连接到小的后面
        */
        if(pHead == NULL)
            return pHead;
        //小链表哨兵节点
        ListNode * smallHead = (ListNode *)malloc(sizeof(ListNode));
        smallHead->next = NULL;
        ListNode * scur = smallHead;
        //大链表哨兵节点
        ListNode * bigHead = (ListNode *)malloc(sizeof(ListNode));
        bigHead->next = NULL;
        ListNode * bcur = bigHead;
        
        ListNode * cur = pHead;
        //遍历链表
        while(cur)
        {
            //小于x插入到小链表
            if(cur->val<x)
            {
                scur->next = cur;
                scur = scur->next;
            }
            else
            {
                bcur->next = cur;
                bcur=bcur->next;
            }
            cur=cur->next;
        }
        //让大小链表的尾节点分别指向空，防止死循环
        bcur->next = NULL;
        scur->next = NULL;
        //没有小于x的几点
        if(NULL == smallHead->next)
        {
            return bigHead->next;
        }
        //有小于x的节点
        scur->next=bigHead->next;
        return smallHead->next;
    }
};