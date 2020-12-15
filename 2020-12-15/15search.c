//�������������е����ֵĴ���������ʶ��Ҫ��Ӧ���ֲ��ң�
//���������������ǲ��ҵ�ֵtarget�������ж������ʱ��Ͳ�������ͨ�Ķ��ֲ����������ˣ�
//����Ŀ��ֵ�϶�������һ��ģ����������Ҫ�ҵ��⼸������һ�����ʼ�������ֹ���꣬���ǵĲ�ֵ��������
//��ҪĿ��ֵ�ĸ���(ע��߽磬��ͬ��������ֵ��һ������))���Ҳ��õ����������ҵ�Ŀ��ֵ���ұ߽߱缴
//nums[right - 1] = target����Ѱ��
//target - 1���ұ߽߱磬��nums[right] = target��������������ΪĿ��ֵ�ĸ�����
//��Ѱ�ҵ�һ���ұ߽��ʱ�����ǿ���ͨ����һ�εı߽��ж��Ƿ����Ŀ��ֵ��
//��� ��һ��Ѱ�ҵ�Ŀ��ֵ target <= 0 || target >= numsSize����ô����֮�в�����Ŀ��ֵ��
//��ʱֱ�ӷ���0�����ٽ��еڶ��β��ң�
int Binearch(int *nums, int numsSize, int target)//��װһ���ұ߽���ֲ���
{
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (target<nums[mid])
			right = mid - 1;
		else if (target>nums[mid])
			left = mid + 1;
		else//�ҵ���
			left = mid + 1;
	}
	return left;//�����ұ߽��
}

int search(int* nums, int numsSize, int target){
	int R_right = Binearch(nums, numsSize, target);//�ҵ���һ���ұ߽��
	if (R_right <= 0 && R_right >= numsSize)//������û��Ŀ��ֵ
		return 0;
	int L_right = Binearch(nums, numsSize, (target - 1));//�ҵ�target-1�ı߽�
	return (R_right - L_right);

}