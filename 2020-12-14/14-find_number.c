#include <stdio.h>
#include <windows.h>
//��һ������Ϊ n ������ nums ����������ֶ��� 0��n - 1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//

int  com(int *x, int *y)
{
	if (*x>*y)
		return 1;
	else if (*x<*y)
		return -1;
	else
		return 0;
}

int findRepeatNumber(int* nums, int numsSize){
	//�������ڱȽ���������
	qsort(nums, numsSize, sizeof(int), com);

	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return nums[i];
	}
	return nums[0];

}