//在一个?XY 坐标系中有一些点，我们用数组?coordinates?来分别记录它们的坐标，
//其中?coordinates[i] = [x, y]?表示横坐标为 x、纵坐标为 y?的点。
//请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。


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

