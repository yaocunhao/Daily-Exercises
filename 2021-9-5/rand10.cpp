// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int Getrand()
    {
        return (rand7()-1)*7+rand7();
    }
    int rand10() {
       // (rand7()−1)∗7+rand7()
       //rand7()-1 得到的随机数值的区间为[0,6]
       //[0,6]*7 得到等概率数值为 0,7,14,21....42，每个数字之间的间隔为7
       //在加上随机数 [1,7] 最终结果的范围为[0,49],
       //由于每个数字之间的间隔为7，因此生成的新的[0,49]的概率都是一样的


    //直接采用加法会导致每个数字的概率不相等

       int  num=Getrand();
       while(num>40)
       {
           num=Getrand();
       }
       return num%10+1;
    }
};