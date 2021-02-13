int maxPower(char * s){
	int slow = 0;
	int fast = 0;
	int maxLen = 0;
	int len = strlen(s);
	while (fast < len) {
		slow = fast;
		while (s[slow] == s[fast]) {
			fast++;
		}
		maxLen = maxLen >(fast - slow) ? maxLen : (fast - slow);

	}
	return maxLen;
}
