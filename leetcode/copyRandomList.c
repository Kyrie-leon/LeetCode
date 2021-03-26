/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */


typedef struct Node Node;

//拷贝节点
Node * BuyListNode(int val)
{
    Node * copy = (Node *)malloc(sizeof(Node));
    copy->val = val;
    copy->next = NULL;
    copy->random = NULL;
    return copy;
}

struct Node* copyRandomList(struct Node* head) {
	if(head == NULL)
    {
        return NULL;
    }
    //1.拷贝节点到原链表的后面
    Node * source = head;   //source指向原节点
    Node * next = NULL;
    Node * copy = NULL; 
    //遍历节点开始拷贝
    while(source)
    {   
        //source next
        next = source->next; //next指向原节点的后一个节点
        copy = BuyListNode(source->val); //拷贝节点
        source->next = copy;    //原节点指向拷贝节点
        copy->next = next;      //拷贝节点指向原节点的第二个节点
        //|source copy next | source后移
        source = next;
    }

    //********错误1：先拷贝节点随机指针再分离链表*******
    //2.拷贝随机指针
    source  = head;
    while(source)
    {
        copy = source->next;
        next = copy->next;
        //source的random是否指向NULL
        if(source->random != NULL)
        {
            copy->random = source->random->next;    //拷贝节点的random指向原节点random的下一个节点
        }    
        source = next;
    }

    //3.恢复原链表，并将拷贝出的节点单独成链表
    source = head;  //source指向头节点
    Node * copynext = NULL;
    Node * copyHead = head->next;   //拷贝链表的头节点
    while(source)
    {
        //source copy next copynext
        copy = source->next;
        next = copy->next;
        source->next = next;    //source 后移
        source = next;
        //next是否为NULL
        if(next!=NULL)
        {
            copynext = next->next;
            copy->next = copynext;
        }

    }
    return copyHead;
}