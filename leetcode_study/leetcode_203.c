#include <stdlib.h>



struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode list_node_t;

list_node_t*
removeElements(
    list_node_t*    head,
    int             val
) 
{
    list_node_t* cur = head;
    list_node_t* pre;
    //这个地方可以 优化 用虚拟头节点减少 初始化pre的过程
    //先处理头节点
    while(cur != NULL && cur->val == val)
    {
        head = head->next;
        free(cur);
        cur = head;
    }
    head    = cur;
    pre     = cur;

    if(head == NULL)
    {
        return head;
    }
    cur     = cur ->next;

    while(cur != NULL)
    {
        if(cur->val == val)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
            continue;
        }
        pre = cur;
        cur = cur->next;
    }
    return head;
}