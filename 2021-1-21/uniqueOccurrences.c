bool uniqueOccurrences(int* arr, int arrSize){
	int *b = (int *)calloc(2001, sizeof(int));
	for (int i = 0; i < arrSize; i++){
		if (arr[i] >= 0)
			b[arr[i]]++;
		else
			b[abs(arr[i]) + 1000]++;
	}
	int *c = (int *)calloc(1001, sizeof(int));
	for (int i = 0; i < 2001; i++){ // 注意此处的i,范围是0~2000,不是1001,因为i要进到b[i]中
		if (((++c[b[i]]) > 1) && (b[i] != 0))
			return false;
	}
	return true;
}
