#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode listnode_t;

struct ListNode* 
reverseList(
    struct ListNode* head
) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    listnode_t* cur;
    listnode_t* pre;
    listnode_t* next;

    pre     = NULL;
    cur     = head;
    next    = head->next;

    while(next != NULL)
    {
        cur->next   = pre;
        pre         = cur;
        cur         = next;
        next        = next->next;
    }
    cur->next = pre;
    return cur;
}