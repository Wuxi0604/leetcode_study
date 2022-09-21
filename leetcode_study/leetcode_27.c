
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
遇到目标数字后，和末尾指针指向的可用的数据进行交换
这种方式改变了数据的相对顺序，不太好

可以使用前后双指针去解决,并不是双向而行，同向而行
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