//给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。
//另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。
//
//思路：由于数组是有序的，直接遍历比较即可，如果遍历完还没有找到则直接放回数组的第一个元素

char nextGreatestLetter(char* letters, int lettersSize, char target){
	for (int i = 0; i<lettersSize; i++)
	{
		if (letters[i]>target)
			return letters[i];//找到了
	}
	//没找到
	return letters[0];
}