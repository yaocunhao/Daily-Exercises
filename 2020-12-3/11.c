//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/�����������

class Solution {
public:
	int Add(int num1, int num2)
	{
		int count = 0;
		if (num2 >= 0)
		{
			while (count != num2)
			{
				num1++;
				count++;
			}
			return num1;
		}
		else
		{
			count = (num2*(-1));
			while (count)
			{
				num1--;
				count--;
			}
			return num1;
		}

	}
};