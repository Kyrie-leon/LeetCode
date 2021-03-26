/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        
    //1、链表为空或者只有一个节点则返回true
        if(A==NULL || A->next==NULL)
            return true;
    //2.链表多于一个节点
        ListNode * pfast = A;    //快指针
        ListNode * pslow = A;    //慢指针
        //偶数个节点时fast==NULL结束，奇数个节点时fast->next==NULL结束
        //while继续循环的条件是继续的条件，而我们思考的是while停止的条件，因此是条件反过来的
        while(!(pfast == NULL || pfast->next == NULL))    
        {
            pfast = pfast->next->next;    //快指针一次走两步
            pslow = pslow->next;           //慢指针一次走一步
        }
        
        //逆置节点,采用头插法,每次从链表中取出一个节点插入到pre节点之前
        ListNode * prev = pslow;    
        pslow = pslow->next;
        prev->next = NULL;    //中间节点置空
        while(pslow!=NULL)
        {
            ListNode * tmp =pslow->next;    //保存当前节点的后一个节点防止丢失
            pslow->next=prev;    //当前节点指向前一个节点
            prev=pslow;    //prev和pslow分别后移
            pslow=tmp;
        }
        
        
        ListNode * pleft = A;    //指向头节点
        ListNode * pright = prev;    //指向尾节点
        while(!(pleft==pright || pleft->next == pright))
        {
            if(pleft->val != pright->val)
                return false;
            else
            {
                pleft = pleft->next;
                pright = pright->next;
            }
        }
        return true;
    }
};