//实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

//解法：利用数组来统计不同的元素出现的个数，数组的下标即字母-'a',因此需要开辟的数组空间为26个



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