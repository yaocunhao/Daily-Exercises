class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		//将每个位置的0/1数量和对应的下标 记录下来
		//从前往后进行遍历，这样可以找到对应的子数组
		//当nums[i]==0 ， count-- 否则count++
		//假设在sub位置 count=2，表示0-sub 子数组中，1多了两个 ->
		//需要在前面

		unordered_map<int, int> mp;
		int count = 0;
		int max = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] == 0)
				count--;
			else
				count++;

			if (count == 0)
				max = i + 1;

			if (mp.find(count) == mp.end())
				mp[count] = i;
			else
				max = fmax(max, i - mp[count]);
		}
		return max;
	}
};