//����������Сд��ĸ���ɵ��ַ���?A?��?B?��ֻҪ���ǿ���ͨ������ A �е�������ĸ�õ��� B ��ȵĽ�����ͷ���?true?�����򷵻� false ��
//
//������ĸ�Ķ�����ȡ�����±� i �� j ���±�� 0 ��ʼ����ֻҪ i != j �ͽ���





bool buddyStrings(char * A, char * B){
	if (*A == '\0' || B == '\0')
		return false;

	if (strcmp(A, B) == 0)//�ж��ַ����Ƿ����
	{
		int lable = *A;
		while (*A)
		{
			if (*A != lable)
				return false;//�����ַ�����ȣ��Ҳ�����һ���ַ�����
			A++;
		}
		return true;
	}

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	while (*A)
	{
		count1 += *A;
		count2 += *B;
		if (*A != *B)
			count3++;
		A++;
		B++;
	}
	if (count1 == count2&&*B == '\0'&&count3<3)
		return true;
	return false;

}