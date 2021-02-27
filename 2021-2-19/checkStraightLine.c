//在一个?XY 坐标系中有一些点，我们用数组?coordinates?来分别记录它们的坐标，
//其中?coordinates[i] = [x, y]?表示横坐标为 x、纵坐标为 y?的点。
//请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。


//思路：利用斜率来解题，注意除数为零的情况

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

