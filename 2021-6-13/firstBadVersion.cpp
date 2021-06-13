class Solution {
public:
    int firstBadVersion(int n) {
        int left=0;
        int right=n;
        int mid=left+(right-left)/2;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(isBadVersion(mid)==false)//前面的没错
                left=mid+1;
            else//后面的没错
                right=mid;
        }

        return right;
    }
};