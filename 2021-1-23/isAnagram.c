���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

bool isAnagram(char * s, char * t){

	int len_s = strlen(s);
	int len_t = strlen(t);
	if (len_s != len_t)//���Ȳ����
		return false;

	int str[26] = { 0 };//26����ͬ����ĸ

	for (int i = 0; i<len_t; i++)
	{
		str[s[i] - 'a']++;//���Ϊs[i]==a���±���Ϊ0���Դ�����
		str[t[i] - 'a']--;
	}
	for (int i = 0; i<26; i++)//�����Ӧ��str���в�Ϊ0��Ԫ�أ�������ĸ��λ��
	{
		if (str[i] != 0)
			return false;
	}
	return true;
}