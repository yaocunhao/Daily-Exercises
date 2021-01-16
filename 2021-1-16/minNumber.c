输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。







int compare(void *a, void *b)
{
	char temp1[100] = "", temp2[100] = "";
	char *s1 = *(char **)a, *s2 = *(char **)b;
	strcat(temp1, s1);
	strcat(temp1, s2);
	strcat(temp2, s2);
	strcat(temp2, s1);
	return atof(temp1) - atof(temp2);
}

char* minNumber(int* nums, int numsSize){
	char **str = (char **)malloc(sizeof(char *)*numsSize);
	for (int i = 0; i<numsSize; i++)
	{
		str[i] = (char *)malloc(sizeof(char)* 20);
		sprintf(str[i], "%d", nums[i]);
	}
	qsort(str, numsSize, sizeof(char *), compare);
	char *result = (char *)malloc(sizeof(char)* 5000);
	memset(result, 0, sizeof(result));
	for (int i = 0; i<numsSize; i++)
		strcat(result, str[i]);
	return result;
}
