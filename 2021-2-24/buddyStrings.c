//给定两个由小写字母构成的字符串?A?和?B?，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回?true?；否则返回 false 。
//
//交换字母的定义是取两个下标 i 和 j （下标从 0 开始），只要 i != j 就交换





bool buddyStrings(char * A, char * B){
	if (*A == '\0' || B == '\0')
		return false;

	if (strcmp(A, B) == 0)//判断字符串是否相等
	{
		int lable = *A;
		while (*A)
		{
			if (*A != lable)
				return false;//两个字符串相等，且不是由一种字符构成
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