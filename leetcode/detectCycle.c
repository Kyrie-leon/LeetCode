/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    //˼�룺
    //1.ʹ�ÿ���ָ���ҵ������� 2.�������㿪ʼ�������ڵ���ȵĵ�����ཻ��
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode * slow = head;
    ListNode * fast = head;
    ListNode * meet = NULL; //������
    ListNode * slowHead = NULL; //slow����ͷ�ڵ�

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //�ҵ��������˳�ѭ��
        if(fast == slow)
        {
            meet = fast;   
            slowHead = fast->next;//slow�������ʼ�ڵ�Ϊ���������һ���ڵ�
            break;      //����һ��û��дbreak��䵼��������ѭ��
        }
    }

    //û����������������޻�ֱ�ӷ���
    if(meet == NULL)    
    {
        return NULL;
    }

    //���������������ĳ���
    int len_fast = 0;
    int len_slow = 0;
    ListNode * fast_cur = head;
    ListNode * slow_cur = slowHead;

    //ͷ�ڵ㿪ʼ����������fast����
    while(fast_cur!=meet)
    {
        fast_cur = fast_cur->next;
        ++len_fast;
    }

    //slowHead��ʼ������fast����
    while(slow_cur!=meet)
    {
        slow_cur = slow_cur->next;
        ++len_slow; 
    }

    //������������Ĳ�ֵn
    int n = abs(len_slow-len_fast);

    fast_cur = head;
    slow_cur = slowHead;
    if(len_fast > len_slow)
    {   
        //fast��������n��
        while(n--)
        {
            fast_cur = fast_cur->next;
        }
    }
    else if(len_fast < len_slow)
    {
        //slow����n��
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
