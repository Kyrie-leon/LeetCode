/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val){

    //1.不带头节点,头节点的值为val
    while(head!=NULL && head->val==val)
    {
        head=head->next;    //头节点后移
    }
    if(head==NULL)
    {
        return head;
    }
    //2.头节点的值不为空
    Node * prev=head;   //由于情况1里已经考虑到头节点等于val的可能，因此prev指向头节点
    Node * cur=head->next;  //cur指向头节点的下一个节点，代表当前节点
    //遍历当前节点，如果当前节点为空代表遍历链表结束
    while(cur!=NULL)
    {
        //如果当前节点的val等于给点的val值，就让pre->指向当前节点的下一个节点
        if(val == cur->val)
        {
            prev->next=cur->next;
        }
        //如果不相等，就让prev后移
        else
        {
            prev=cur;
        }
        //cur后移
        cur=cur->next;
    }
    
    return head;
}
