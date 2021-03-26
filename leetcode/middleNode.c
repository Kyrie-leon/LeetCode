/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head){
    //快慢指针实现
    if(head ==NULL || head->next == NULL)
    {
        return head;
    }

    ListNode * slow = head;
    ListNode * fast = head;

    //快指针一次走两步，慢指针一次一步
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}