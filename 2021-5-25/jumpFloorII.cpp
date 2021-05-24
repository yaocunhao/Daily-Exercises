class Solution {
public:
    int jumpFloorII(int number) {
        // 1  2  3  5 
    //跳到当前位置的总数 = 前面所有的总数加起来
    //给定两个变量，一个保存当前位置的总数，一个保存所有的总和
        
        int sum=1;
        int jump=1;
        while(number--)
        {
            jump=sum;
            sum+=jump;
        }
         return jump;
    }
};