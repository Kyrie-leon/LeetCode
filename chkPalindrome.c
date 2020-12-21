/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        //边加边减
        if(A==NULL || A->next==NULL)
            return false;
        int flag=1;
        int sum=0;
        while(A!=NULL)
        {
            sum += A->val*flag;
            A=A->next;
            flag *= -1;
        }
        if(sum=0)
            return true;
        else
            return false;
    }
};