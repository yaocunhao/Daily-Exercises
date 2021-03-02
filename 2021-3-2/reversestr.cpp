void reverseStr(char *s)
{
	int i;
	int len = strlen(s);
	char ch;

	for (i = 0; i < len / 2; i++) {
		ch = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = ch;
	}
}

char *reverseWords(char *s)
{
	char space[] = " ";
	char *word = NULL;
	int i;
	int cnt = 0;
	int len = strlen(s);
	char *str = (char *)malloc(len * sizeof(char)+1);
	if (s == NULL || len == 0 || str == NULL) {
		return s;
	}
	memset(str, '\0', len * sizeof(char)+1);

	reverseStr(s);
	word = strtok(s, space);
	while (word != NULL) {
		reverseStr(word);
		for (i = 0; i < strlen(word); i++) {
			str[cnt++] = word[i];
		}
		str[cnt++] = ' ';
		word = strtok(NULL, space);
	}
	if (cnt > 0) {
		str[cnt - 1] = '\0';
	}
	return str;
}

