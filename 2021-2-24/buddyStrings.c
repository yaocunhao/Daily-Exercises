//给定两个由小写字母构成的字符串?A?和?B?，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回?true?；否则返回 false 。
//
//交换字母的定义是取两个下标 i 和 j （下标从 0 开始），只要 i != j 就交换

//思路：分为字符串相等和不相等的情况，相等则判断是否有重复的字母，如果有则表示可以进行交换
//不相等的情况下，判断两个字符串的长度是否相等，字符串的总体是否相等，以及相差的字母是否为两个

bool buddyStrings(char * A, char * B){
	if (*A == '\0' || B == '\0')
		return false;

	if (strcmp(A, B) == 0)//如果两个字符串相等
	{
		char str[26] = { 0 };
		while (*A)
		{
			str[*A - 'a']++;
			A++;
		}
		for (int i = 0; i<26; i++)
		{
			if (str[i]>1)
				return true;
		}
		return false;
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