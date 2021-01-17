int hammingWeight(uint32_t n) {
	int cnt = 0;
	while (0 != n) {
		cnt++;
		n &= (n - 1);
	}
	return cnt;
}

