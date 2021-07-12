class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left=0;
        int right=citations.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int num=citations.size()-mid;

            if(citations[mid]>=num)
                right=mid-1;
            else
                left=mid+1;
        }
        return citations.size()-left;
    }
};