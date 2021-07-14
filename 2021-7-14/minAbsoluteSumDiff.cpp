class Solution {
public:

        int binarySearch(vector<int>& arr,int target)
        {

            //两种极端情况
            if(target<=arr[0])
                return arr[0];
            if(target>=arr.back())
                 return arr.back();

            int left=0;
            int right=arr.size()-1;

            while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(arr[mid]<target)
                    left=mid+1;
                else if(arr[mid]>target)
                    right=mid-1;
                else
                    return arr[mid];
            }

            int val1=abs(arr[left] - target);
            int val2=abs(arr[right] - target);

        //返回差值更小的值
            if(val1 < val2)
                return arr[left];

            return arr[right];

        }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        //开辟一个数组，统计每个位置替换前后的差值，最后差值最大的那个位置就被替换掉
        vector<int> arr(nums1);

        sort(arr.begin(),arr.end());//排序

        int count=0;//记录差值
        int sub=-1;//记录需要被替换位置的下标
        int record=0;

        for(int i=0;i<nums1.size();i++)
        {
            int val1=abs(nums1[i]-nums2[i]);//替换前的差值
            int val2=abs(binarySearch(arr,nums2[i])-nums2[i]);//替换后的差值

            //val1 - val2 弥补的差值
            //如果替换后差值更小，则将这个替换后的值保存下来
            //如果另外一个位置，替换后的值，比当前位置弥补的差值更大，则替换另外一个位置
            if(val1 -val2>count)
            {
                sub=i;//记录那个位置被替换了
                record=val2;//记录这个位置的差值被替换成了多少
                count=val1 - val2;//记录弥补的最大差值
            }
        }

        int sum=0;
        int div=pow(10,9)+7;
        for(int i=0;i<nums1.size();i++)
        {
            if(i==sub)//需要被替换的位置
            {
                sum=(sum+record)%div;
            }
            else    
                sum=(sum+abs(nums1[i] - nums2[i]))%div;
        }

        return sum;
    }
};