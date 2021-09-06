class Solution {
public:
    int balancedStringSplit(string s) {
        //要求将s分割成小的字符串，每个小字符串之中的L和R的字符是相等的

        //根据贪心的原理，总的LR是相等的，那么前面分出去的小串越短越分得多
        int count=0;
        int size=0;
        for(auto&e:s)
        {
            if(e=='L')
                size++;
            else
                size--;

            if(size==0)
                count++;
        }
        return count;
    }
};