//### 解题思路
//小写字母总共26个，因此创建一个array[26]的数组，
//再将字符串中依次出现的字符 - ‘a’得到对应的0 - 25小标，再数组内容 + 1;
//第二次遍历进行读取，对应的字符小标为1的则出现了一次
//### 代码


char firstUniqChar(char* s){
	int arr[26] = { 0 };
	for (int i = 0; i<strlen(s); i++)
	{
		arr[s[i] - 'a']++;//出现一次则+1；
	}

	for (int i = 0; i<strlen(s); i++)
	{
		if (arr[s[i] - 'a'] == 1)//找到只出现一次的字符；
			return s[i];
	}

	return ' ';

}
