/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct ListNode Node;

//逆置后输入到数组中
int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int count = 0;
    Node* cur = head;
    Node* prev = NULL;
    Node* next = head->next;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        head = prev;
        cur = next;
        count++;
    }
    *returnSize = count;
    cur = head;
    int* retArr = (int *)malloc(sizeof(int)*count);
    int i = 0;
    while(cur)
    {
       retArr[i++] = cur->val;
       cur = cur->next;
    }
    return retArr;
}

/*倒序输入到数组中
int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
        
    int count = 0;
    Node* cur = head;
 
    while(cur)
    {
        cur = cur->next;
        //计数
        ++count;
    }
    *returnSize = count;
    int* retArr = (int *)malloc(sizeof(int)*count);
    cur = head;
    while(cur)
    {
       retArr[count-1] = cur->val;
       --count;
       cur = cur->next;
    }
    return retArr;
}
*/