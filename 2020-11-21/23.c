#include <stdio.h>
#include <windows.h>
//��ӡ������ͼ�������Σ���

          // *
          //***
         //*****
        //*******
       //  *****
         // ***
         //  *
void PrinDiamod()
{
	for (int i = 1; i < 5; i++)//�����ϰ벿������
	{
		for (int k =10; k>i; k--)//�ո�
		{
			printf(" ");
		}
		for (int j = 0; j < i * 2 - 1; j++)//����
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 3; i>0; i--)//�°벿��
	{
		for (int k = 10; k > i; k--)
		{
			printf(" ");
		}
		for (int j = 0; j < i*2-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

}
int main()
{
	PrinDiamod();
	system("pause");
	return 0;
}