/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    /***************˼·***********
    ����ȷ���������ͷ�ڵ㣬Ȼ��������ָ��Ƚ����������val��������
    ******************************/
    //1.��������Ϊ��
    if(l1==NULL && l2==NULL)
    {
        return NULL;
    }
    //2.һ��Ϊ��һ����Ϊ��
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
        //Ĭ��l1Ϊͷ�ڵ�
        ListNode * newHead= (ListNode *)malloc(sizeof(ListNode));    //����һ���ڱ��ڵ�
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
        //˭������˭
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
