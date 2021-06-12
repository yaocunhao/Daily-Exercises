#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin.sync();

	while (getline(cin, str))
	{

			//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z	密码字母
			//V W X Y Z A B C D E F G H I J K L M N O P Q R S T U	原文字母

		for (int i = 0; i<str.size(); i++)
		{
			if (str[i] == ' ')
			{
				cout << str[i];
				continue;
			}
			else
			{
				int num = str[i] - 5;
				if (num < 'A')
				{
					int num2 = 'A' - num; //得到比A小多少
					str[i] = 'Z' - num2+1;
				}
				else
					str[i] = num;
			}

			cout << str[i];
		}
		cout << endl;
	}

	return 0;
}
