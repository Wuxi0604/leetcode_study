

int 
minSubArrayLen(
    int     target, 
    int*    nums, 
    int     numsSize
) 
{
    //使用前后指针,两个指针之间的内容为和
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

    //结束条件  指针指向数组外，并且此时的sum > target 要想循环继续下去
    while(next != numsSize || sum > target)
    {
        //这个判断可以优化掉，不需要
 //       if(sum < target)
 //       {
            sum += nums[next++];
//        }
        //front前进不止一步
        while(sum >= target)
        {
            //next 本身已经加1, 所以不需要再加1了
            ret_len = ret_len > next - front ? next - front : ret_len;
            sum = sum - nums[front++];
        }
    }
    //根据front的值是否变化来判断 全部和值小于target 还是最小长度刚好为numsSize
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