#include <stdio.h>
#include <windows.h>
//����ƹ����ӽ��б������������ˡ��׶�Ϊa��b��c���ˣ��Ҷ�Ϊx��y��z���ˡ�
//�ѳ�ǩ���������������������Ա��������������.a˵������x�ȣ�c˵������x��z�ȣ��������ҳ��������ֵ�������
void Roll()
{
	char i = 0;
	char j = 0;
	char k = 0;
	for (i = 'x'; i <= 'z';i++)
	{
		for (j = 'x'; j <= 'z'; j++)
		{
			if (i != j)
			{
				for (k = 'x'; k <= 'z'; k++)
				{
					if (j != k&&i!= k)//3��if�ж�ʹ��ijkΪabc������������
					{
						if (i != 'x'&&k!='x'&&k!='z')
							printf("a--%c,b--%c,c--%c",i,j,k);
					}
				}
			}
		}
	}
}
int main()
{
    Roll();
	system("pause");
	return 0;
}