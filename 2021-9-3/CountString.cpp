void Count(string str, int n, int &count)
{
	//出口
	if (str.size() >= 3)
	{
		string temp(str.begin() + str.size() - 3, str.end());//最后的三个字符
		if (temp == "aba" || temp == "bab")//相等了
			return;
	}
	
	//n个位置全部填满了
	if (str.size() == n)
	{
		count++;
		return;
	}

	//后面的位置为a或者为b
	Count(str + "a", n, count);
	Count(str + "b", n, count);
}

int main()
{
	int count = 0;
	Count("a", 3, count);
	Count("b", 3, count);

	cout << count << endl;
	getchar();
	return 0;
}