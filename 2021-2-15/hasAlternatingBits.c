//����һ����������������Ķ����Ʊ�ʾ�Ƿ����� 0��1 ������֣�
//���仰˵�����Ƕ����Ʊ�ʾ��������λ������������ͬ��

//˼·��ͨ��ѭ��N������С2�����жϼ���Ķ������Ƿ���ȼ���

bool hasAlternatingBits(int n){

	while (n)
	{
		int first = n % 2;
		n = n / 2;
		int second = n % 2;

		if (first == second)
			return false;
	}
	return true;

}