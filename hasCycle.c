/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head) {
    //快慢指针,快指着呢一次两步慢指针一次一步，快慢指针相等即为相交点
    if(head==NULL || head->next == NULL)
    {
        return false;
    }
    ListNode * slow = head;
    ListNode * fast = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;    //快指针一次走2步
        if(fast == slow)
        {
            return true;
        }
    }

    return false;
}
