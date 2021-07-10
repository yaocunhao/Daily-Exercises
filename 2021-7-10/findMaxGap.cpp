class MaxGap {
public:
    int findMaxGap(vector<int> arr, int n) {
        //划分后，两个最大值的差绝对值最大 ->
        vector<int> left(n-1,0);
        vector<int> right(n-1,0);
        //left[i] 表示以i为分界线时，左边界的最大值
        //right[i] 表示以i为分界线时，右边界的最大值
        
        left[0]=arr[0];
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]>left[i-1])
                left[i]=arr[i];
            else
                left[i]=left[i-1];
        }
        
        right[n-2]=arr[n-1];
        for(int i=n-2;i>0;i--)
        {
             if(arr[i]>right[i])
                right[i-1]=arr[i];
            else
                right[i-1]=right[i];
        }
        
        int max=abs(left[0]-right[0]);
        for(int i=0;i<n-1;i++)
        {
            int val=abs(left[i]-right[i]);
            if(val>max)
                max=val;
        }
        return max;
    }
};