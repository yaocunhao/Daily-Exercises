����ת������дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת������B��

int convertInteger(int A, int B){
	//�ж�A��B�Ķ������е�λ�м�����ͬ�������������ͬ
	unsigned int c = A^B;//ע��Խ��
	int ret = 0;
	while (c)
	{
		c = c&(c - 1);//ÿ������һ��1
		ret += 1;
	}
	return ret;
}