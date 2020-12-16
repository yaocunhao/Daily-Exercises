ɽ�����飬�������⼴��һ�������ҽ������飬���ֲ��ҵ�����������������ģ����������Ҫ�ҵ������ɽ�������ߵ㼴����������������Ȼ���ǿ������ö��ֲ�����������������
����߽�Ϊleft���ұ߽�Ϊright���м��Ϊmid��
��nums[mid]>nums[mid - 1]��ʱ�򣬴�ʱmidΪɽ������������������м䣬���left = mid��Ϊʲô����mid + 1�أ���Ϊmid�п�����ɽ�������mid + 1����������ֵ��
ͬ��nums[mid]>nums[mid + 1]��midλ��ɽ�������ұ߽�������֮�䣬���right = mid��
ֱ��ѭ��������left = right����ʱ��Ϊɽ����

int findInMountainArray(int target, MountainArray* mountainArr) {
	int left = 0;
	int right = length(mountainArr) - 1;

	while (left<right)//�ҵ�ɽ��
	{
		int mid = left + (right - left) / 2;
		if (get(mountainArr, mid)>get(mountainArr, mid - 1))
			left = mid;
		if (get(mountainArr, mid)>get(mountainArr, mid + 1))//���Ҳ�
			right = mid;
	}

	//�����������
	int newleft = 0;
	int newright = length(mountainArr) - 1;
	while (newleft <= left)
	{
		int mid = newleft + (left - newleft) / 2;
		if (get(mountainArr, mid)<target)
			newleft = mid + 1;
		else if (get(mountainArr, mid)>target)
			left = mid - 1;
		else
			return mid;
	}

	//�Ҳཱུ������
	while (right <= newright)
	{
		int mid = right + (newright - right) / 2;
		if (get(mountainArr, mid)>target)
			right = mid + 1;
		else if (get(mountainArr, mid)<target)
			newright = mid - 1;
		else
			return mid;
	}
	return -1;
}