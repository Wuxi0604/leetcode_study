
void
swap(
    int*  nums,
    int   index1,
    int   index2
)
{
    int temp     = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}
/*
����Ŀ�����ֺ󣬺�ĩβָ��ָ��Ŀ��õ����ݽ��н���
���ַ�ʽ�ı������ݵ����˳�򣬲�̫��

����ʹ��ǰ��˫ָ��ȥ���,������˫����У�ͬ�����
*/
int 
removeElement(
    int* nums, 
    int  numsSize, 
    int  val
) {
    int left = 0;
    for(int right = 0; right < numsSize; right++) {
        if(nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}

int
main()
{
    int nums[4] = {3, 2, 2, 3};
    removeElement(nums, 4, 3);
}