//�޷��ţ���˿��������ַ���
//int hammingWeight(uint32_t n) {
//	int count = 0;
//	while (n)
//	{
//		if (n & 1 == 1)
//			count++;
//		n >>= 1;
//	}
//	return count;
//}


����2��
int hammingWeight(uint32_t n) {
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}