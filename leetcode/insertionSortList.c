/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head){

    if(head == NULL)
        return head;

    //定义排序链表的头结点，链表的第一个节点
    ListNode* sortHead = head;
    ListNode* cur = head->next; //从链表的第二个结点开始比较排序
    sortHead->next = NULL;  //排序链表作为一个新的链表
  
    while(cur)
    {
        
        ListNode* next = cur->next;
        //链表节点小于排序节点的头结点，头插
        if(cur->val <= sortHead->val)
        {
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            ListNode* sortPrev = sortHead;
            ListNode* sortCur = sortHead->next;

            //中间插
            while(sortCur)
            {
                //插入到sortCur前面
                if(cur->val <= sortCur->val)
                {
                    sortPrev->next = cur;
                    cur->next=sortCur;
                    break;
                }
                else
                {
                    sortPrev = sortCur;
                    sortCur=sortCur->next;
                }
            }

            //尾插
            if(sortCur == NULL)
            {
                sortPrev->next = cur;
                cur->next=NULL;
            }
        }
        cur = next;
        
    }

    return sortHead;
}