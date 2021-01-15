/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //空结点或者单节点直接返回
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        
        ListNode* prev = NULL;
        ListNode* cur = pHead;
        ListNode* next = cur->next;
        
        while(next)
        {
            //当前节点val不等于next节点val，三个指针同时走
            if( cur->val != next->val)
            {
                prev = cur;
                cur = next;
                next=next->next;    //next向右移动
            }
            else
            {
                //next右移到不等于cur
                while(next && cur->val == next->val)
                {
                    next=next->next;
                }
                
                //头结点出现相同值情况，prev为空，重新制定头结点
                if(prev)
                {
                    prev->next = next;
                }
                else
                {
                    pHead = next;
                }
                
                while(cur != next)
                {
                    ListNode* del = cur;
                    cur = cur->next;
                    free(del);
                }
                if(next)
                {
                    next = next->next;
                }
            }
            
        }
        
        return pHead;

    }
};