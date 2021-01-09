给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
你可以按任意顺序返回答案。


//解题思路：双层循环寻找






int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *arr=(int *)malloc(sizeof(int)*2);

    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                arr[0]=i;
                arr[1]=j;
                *returnSize=2;
                return arr;
            }
        }
    }
    *returnSize=0;
    return arr;

}