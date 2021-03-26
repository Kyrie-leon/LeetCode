/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head) {
    //����ָ��,��ָ����һ��������ָ��һ��һ��������ָ����ȼ�Ϊ�ཻ��
    if(head==NULL || head->next == NULL)
    {
        return false;
    }
    ListNode * slow = head;
    ListNode * fast = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;    //��ָ��һ����2��
        if(fast == slow)
        {
            return true;
        }
    }

    return false;
}
