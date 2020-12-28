/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    //思想：
    //1.使用快慢指针找到相遇点 2.从相遇点开始遍历到节点相等的点就是相交点
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode * slow = head;
    ListNode * fast = head;
    ListNode * meet = NULL; //相遇点
    ListNode * slowHead = NULL; //slow链表头节点

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //找到相遇点退出循环
        if(fast == slow)
        {
            meet = fast;   
            slowHead = fast->next;//slow链表的起始节点为相遇点的下一个节点
            break;      //错误一：没有写break语句导致陷入死循环
        }
    }

    //没有相遇点代表链表无环直接返回
    if(meet == NULL)    
    {
        return NULL;
    }

    //计算快慢两个链表的长度
    int len_fast = 0;
    int len_slow = 0;
    ListNode * fast_cur = head;
    ListNode * slow_cur = slowHead;

    //头节点开始遍历快链表到fast结束
    while(fast_cur!=meet)
    {
        fast_cur = fast_cur->next;
        ++len_fast;
    }

    //slowHead开始遍历到fast结束
    while(slow_cur!=meet)
    {
        slow_cur = slow_cur->next;
        ++len_slow; 
    }

    //计算两个链表的差值n
    int n = abs(len_slow-len_fast);

    fast_cur = head;
    slow_cur = slowHead;
    if(len_fast > len_slow)
    {   
        //fast链表先走n步
        while(n--)
        {
            fast_cur = fast_cur->next;
        }
    }
    else if(len_fast < len_slow)
    {
        //slow先走n步
        while(n--)
        {
            slow_cur = slow_cur->next;
        }
    }

    while(fast_cur && slow_cur)
    {
        if(fast_cur==slow_cur)
        {
            return fast_cur;
        }

        fast_cur = fast_cur->next;
        slow_cur = slow_cur->next;
    }

    return NULL;
}
