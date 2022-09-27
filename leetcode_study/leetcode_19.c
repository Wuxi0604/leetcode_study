#include<stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode *next;
};


 
typedef struct ListNode listnode_t;

listnode_t*
removeNthFromEnd(
    listnode_t*     head, 
    int             n
) 
{
    //«∞∫Û÷∏’Î
    listnode_t*     front = head;
    listnode_t*     end   = head;
    for(int i = 0; i < n; i++)
    {
        end = end->next;
    }
    if(end == NULL)
    {
        return head->next;
    }
    while(end->next != NULL)
    {
        front = front->next;
        end   = end->next;
    }
    front->next = front->next->next;
    return head;
}