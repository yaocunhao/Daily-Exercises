class Solution {
public:
    int hIndex(vector<int>& citations) {
        //题意转换 -> 某个数是x，比它大的数还有x-1个


        sort(citations.begin(),citations.end());

        for(int i=0;i<citations.size();i++)
        {
            if(citations.size()-i<=citations[i])
                return citations.size()-i;
        }

        return 0;

    }
};