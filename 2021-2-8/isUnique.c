//ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��

//�ⷨ������������ͳ�Ʋ�ͬ��Ԫ�س��ֵĸ�����������±꼴��ĸ-'a',�����Ҫ���ٵ�����ռ�Ϊ26��



bool isUnique(char* astr){
	int str[26] = { 0 };
	int len = strlen(astr);

	for (int i = 0; i<len; i++)
	{
		str[(astr[i] - 'a')]++;
	}
	for (int i = 0; i<26; i++)
	{
		if (str[i]>1)
			return false;
	}
	return true;
}