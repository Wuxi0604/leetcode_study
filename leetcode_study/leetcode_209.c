

int 
minSubArrayLen(
    int     target, 
    int*    nums, 
    int     numsSize
) 
{
    //ʹ��ǰ��ָ��,����ָ��֮�������Ϊ��
    int ret_len = numsSize;
    int front   = 0;
    int next    = 1;
    int sum     = 0;

    if(numsSize == 0)
    {
        return 0;
    }
    if(nums[front] > target)
    {
        return 1;
    }
    sum += nums[front];

    //��������  ָ��ָ�������⣬���Ҵ�ʱ��sum > target Ҫ��ѭ��������ȥ
    while(next != numsSize || sum > target)
    {
        //����жϿ����Ż���������Ҫ
 //       if(sum < target)
 //       {
            sum += nums[next++];
//        }
        //frontǰ����ֹһ��
        while(sum >= target)
        {
            //next �����Ѿ���1, ���Բ���Ҫ�ټ�1��
            ret_len = ret_len > next - front ? next - front : ret_len;
            sum = sum - nums[front++];
        }
    }
    //����front��ֵ�Ƿ�仯���ж� ȫ����ֵС��target ������С���ȸպ�ΪnumsSize
    if(ret_len == numsSize && front == 0)
    {
        return 0;
    }
    return ret_len;
}

int
main()
{
    int nums[5] = {1, 2, 3, 4, 5};
    minSubArrayLen(15, nums, 5);
}