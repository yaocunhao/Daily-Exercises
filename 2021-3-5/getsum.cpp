//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

//���ⷽ����ͨ����ÿ�δ�������Ҫ����������������ɣ���������static��Ա����������ɼ���
//��Ҫע�⣺ţ�����϶��Ƕ������������static�����Զ����㣬�����Ҫ��дһ���������㺯��

class Sum
{
public:
	Sum()
	{
		_ret += _i;
		_i++;
	}
	static void BlackZero()//�����Ƕ���������������Ҫ����̬��������
	{
		_i = 1;
		_ret = 0;
	}
	static int GetRet()
	{
		return _ret;
	}

private:
	static int _i;
	static int _ret;
};
int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Sum().BlackZero();
		Sum arr[n];

		int ret = Sum::GetRet();
		return ret;

	}
};