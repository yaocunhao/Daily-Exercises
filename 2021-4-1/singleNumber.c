力扣：136

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //0和任何数异或都是任何数
        int x=0;
        for(const auto &e:nums)
        {
            x=x^e;
        }
        return x;

    }
};