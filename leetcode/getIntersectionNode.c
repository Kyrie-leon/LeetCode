/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    /***********˼��
    *****��������A��B���������numA��numB�������ֵn���������������n����Ȼ�������� ��ͬʱ��
    ����������ڵ�ĵ�ַ���ʱ�������ҵ����ཻ��
    */
    int numA=0;
    int numB=0;

    ListNode * Acur=headA;
    ListNode * Bcur=headB;
    //����A����ڵ���㳤��
    while(Acur)
    {
        Acur = Acur->next;
        ++numA;
    }
    //����B����ڵ���㳤��
    while(Bcur)
    {
        Bcur = Bcur->next;
        ++numB;
    }
    
    Acur=headA;
    Bcur=headB;
    int n =abs(numA-numB);
    //�Ǹ����������ĸ���������n��
    if(numA>numB)
    {   
        while(n--)
        {
            Acur = Acur->next;
        }
    }
    else if(numA<numB)
    {
        while(n--)
        {
            Bcur = Bcur->next;
        }
    }
    //�����Ժ�ͬʱ�����Ϳ����ҵ��ཻ��
    while(Acur != NULL)
    {
        if(Acur==Bcur)
        {
            return Acur;
        }
        Acur = Acur->next;
        Bcur = Bcur->next;
    }

    return NULL;
}
