//��һ��?XY ����ϵ����һЩ�㣬����������?coordinates?���ֱ��¼���ǵ����꣬
//����?coordinates[i] = [x, y]?��ʾ������Ϊ x��������Ϊ y?�ĵ㡣
//�������жϣ���Щ���Ƿ��ڸ�����ϵ������ͬһ��ֱ���ϣ����򷵻� true�������뷵�� false��


bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
	if (coordinatesSize == 2)
		return true;
	else
	{
		int x = coordinates[1][0] - coordinates[0][0];
		int y = coordinates[1][1] - coordinates[0][1];
		int i;
		for (i = 2; i<coordinatesSize; i++)
		{
			int y1 = coordinates[i][1] - coordinates[0][1];
			int x1 = coordinates[i][0] - coordinates[0][0];
			if (y*x1 != x*y1)
				break;
		}
		return i >= coordinatesSize;
	}

}

