#include <iostream>
using namespace std;
#include <string>
#include <vector>

//将名字写入vector之中，再去查找
int main()
{
	string base;
	string str;
	while (getline(cin, base))
	{
		getline(cin, str);
        vector<string> arr;
        int sub=0;
        while(sub<base.size())
        {
            string temp;
            if(base[sub]=='"')//遇到组合名字
            {
                sub++;
                while(base[sub]!='"')
                {
                    temp+=base[sub];
                    sub++;
                }
                sub+=2;//跳过 " 和 ,
                arr.push_back(temp);
            }
            else//遇到普通名字
            {
                while(sub<base.size()&&base[sub]!=',')
                {
                    temp+=base[sub];
                    sub++;
                }
                arr.push_back(temp);
                sub++;
            }
        }
        
        int flag=1;//重要的
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==str)
            {
                flag=0;
                break;
            }
        }
        
        if (flag == 1)
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
		
	}


	return 0;
}