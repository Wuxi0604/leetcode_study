#include <stdlib.h>

    //��������������һ��ǰ��ָ��
    //����һ������
    //ƽ��
    //�Ƚ�
    //����

int* 
sortedSquares(
    int* nums, 
    int numsSize, 
    int* returnSize
) 
{
    int* ans = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for(int left = 0, right = numsSize - 1, pos = numsSize - 1; left <= right;) {
        if(nums[left] * nums[left] > nums[right] * nums[right]) {
            ans[pos] = nums[left] * nums[left];
            ++left;
        }
        else {
            ans[pos] = nums[right] * nums[right];
            --right;
        }
        --pos;
    }
    return ans;
}