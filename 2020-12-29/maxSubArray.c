//��̬�滮��
//��Ŀ������������������ͣ�������ǲ��ؿ���������ĳ��ȣ�
//ֻ��Ҫ֪��nums[i + 1]��nums[i]�Ĺ�ϵ���ɣ����nums[i]<0, ��ônums[i + 1]���䣬����nums[i + 1] += nums[i];
//����ѭ��֮������ֻ��Ҫ֪�������е����ֵ���ɣ���˶���һ���洢���ֵ�ı���max = nums[0],
//ÿ��ѭ��max����nums[i + 1]�Ƚ�һ�´�С���ϴ�ļ�������max֮��



int maxSubArray(int* nums, int numsSize){

	int max = nums[0];
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] >= 0)
			nums[i + 1] = nums[i] + nums[i + 1];
		max = max>nums[i + 1] ? max : nums[i + 1];
	}
	return max;

}
