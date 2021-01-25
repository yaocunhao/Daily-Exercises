给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

bool isAnagram(char * s, char * t){

	int len_s = strlen(s);
	int len_t = strlen(t);
	if (len_s != len_t)//长度不想等
		return false;

	int str[26] = { 0 };//26个不同的字母

	for (int i = 0; i<len_t; i++)
	{
		str[s[i] - 'a']++;//如果为s[i]==a，下标则为0，以此类推
		str[t[i] - 'a']--;
	}
	for (int i = 0; i<26; i++)//如果对应的str中有不为0的元素，则不是字母异位词
	{
		if (str[i] != 0)
			return false;
	}
	return true;
}