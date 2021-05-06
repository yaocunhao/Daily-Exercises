解码异或后的数组

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret(encoded.size()+1,0);
        ret[0]=first;

        for(int i=0;i<encoded.size();i++)
        {
            ret[i+1]=ret[i]^encoded[i];
        }

        return ret;
    }
};