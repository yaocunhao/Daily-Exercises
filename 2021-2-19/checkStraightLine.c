//��һ��?XY ����ϵ����һЩ�㣬����������?coordinates?���ֱ��¼���ǵ����꣬
//����?coordinates[i] = [x, y]?��ʾ������Ϊ x��������Ϊ y?�ĵ㡣
//�������жϣ���Щ���Ƿ��ڸ�����ϵ������ͬһ��ֱ���ϣ����򷵻� true�������뷵�� false��


//˼·������б�������⣬ע�����Ϊ������

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
	int index = -1;
	double k = 0;
	double lable_y = coordinates[1][1] - coordinates[0][1];
	double lable_x = coordinates[1][0] - coordinates[0][0];
	if (lable_x == 0)
		index = 0;
	else
		k = lable_y / lable_x;

	for (int i = 2; i < coordinatesSize; i++)
	{
		double flag_y = coordinates[i][1] - coordinates[i - 1][1];
		double flag_x = coordinates[i][0] - coordinates[i - 1][0];
		if (index == 0)
		{
			if (flag_x != 0)
				return false;
		}
		else
		{
			if (flag_x == 0)
				return false;
			if (flag_y / flag_x != k)
				return false;
		}
	}
	return true;
}

