class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int count = 0;
		int t = 0;
		for (int i = 0; i<array.size(); i++)
		{
			if (array[i] % 2 != 0)
			{
				for (int j = count; j<i; j++)
				{
					t = array[j + 1];
					array[j + 1] = array[count];
					array[count] = t;
				}
				count++;
			}
		}
	}
};