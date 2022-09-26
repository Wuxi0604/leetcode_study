#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* 
missingTwo(
    int*    nums, 
    int     numsSize, 
    int*    returnSize
) 
{
    int sort_num = 0;
    //拿到 a^b的值
    int full_num = numsSize + 2;
    int i;
    for(i = 0; i < numsSize; i++)
    {
        sort_num ^= nums[i];
    }
    for(i = 1; i <= full_num; i++)
    {
        sort_num ^= i;
    }
    int min_byte_for_sort_num = (sort_num == INT_MIN ? sort_num : sort_num & (-sort_num));
    //根据 min_byte_for_sort_num 将所有2n-2个数分成两类
    int contain_a_type = 0;
    int contain_b_type = 0;
    for(i = 0; i < numsSize; i++)
    {
        int num = nums[i];
        if(num & min_byte_for_sort_num)
        {
            contain_a_type ^= num;
        }
        else
        {
            contain_b_type ^= num;
        }
    }
    for(i = 1; i <= full_num; i++)
    {
        if(i & min_byte_for_sort_num)
        {
            contain_a_type ^= i;
        }
        else
        {
            contain_b_type ^= i;
        }
    }
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = contain_a_type;
    ans[1] = contain_b_type;
    *returnSize = 2;
    return ans;
}