#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的，加密规则如下： 
//每位数字都加上5,然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换。
void Code(int n)
{
	int arr[4] = { 0 };
	int ret = 0;
	arr[0] = (n % 10 + 5) % 10;
	arr[1] = (n / 10 % 10 + 5) % 10;
	arr[2] = (n / 100 % 10 + 5) % 10;
	arr[3] = (n / 1000 + 5) % 10;
	ret = arr[3] + arr[0] * 1000 + arr[1] * 100 + arr[2] * 10;
	printf("交换后的密码为%d\n", ret);

}

int main()
{
	int n = 0;
	printf("请输入密码\n");
	scanf("%d", &n);
		Code(n);
	system("pause");
	return 0;
}