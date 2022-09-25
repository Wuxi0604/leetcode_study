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
    //����ط����� �Ż� ������ͷ�ڵ���� ��ʼ��pre�Ĺ���
    //�ȴ���ͷ�ڵ�
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