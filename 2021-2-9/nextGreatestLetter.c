//����һ���������ַ��б� letters ���б���ֻ����СдӢ����ĸ��
//�����һ��Ŀ����ĸ target������Ѱ������һ�����б����Ŀ����ĸ�����С��ĸ��
//
//˼·����������������ģ�ֱ�ӱ����Ƚϼ��ɣ���������껹û���ҵ���ֱ�ӷŻ�����ĵ�һ��Ԫ��

char nextGreatestLetter(char* letters, int lettersSize, char target){
	for (int i = 0; i<lettersSize; i++)
	{
		if (letters[i]>target)
			return letters[i];//�ҵ���
	}
	//û�ҵ�
	return letters[0];
}