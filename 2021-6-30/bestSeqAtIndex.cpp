class Solution {
public:
int BinarySerach(vector<int>&arr,int num)
    {
        int left=0;
        int right=arr.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]==num)
                return mid;
            else if(arr[mid]<num)
                left++;
            else
                right--;
        }
        return left;
    }

    struct Less
    {
        bool operator()(vector<int>&x,vector<int>&y)
        {
            if(x[0]==y[0])
                return x[1]>y[1];

            return x[0]<y[0];
        }
    };
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        //先将身高和体重合在一起
        vector<vector<int>> arr(height.size(),vector<int>(2,0));
        unordered_set<int> removal;
        for(int i=0;i<height.size();i++)
        {
            arr[i][0]=height[i];
            arr[i][1]=weight[i];
        }

        //对身高进行排序
        sort(arr.begin(),arr.end(),Less());

        //转化为了递增子序列
        vector<int> people;
        for(int i=0;i<arr.size();i++)
        {
            if(people.size()==0||arr[i][1]>people.back())
                people.push_back(arr[i][1]);
            else
            {
                int sub=BinarySerach(people,arr[i][1]);
                people[sub]=arr[i][1];
            }
        }
        return people.size();
    }
};