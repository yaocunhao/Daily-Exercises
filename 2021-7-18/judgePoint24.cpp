class Solution {
public:
    void dfs(vector<double>&cards,bool &flag,double &num)
    {
    //递归出口
        if(flag)//表示已经有符合要求的了，不再进行后续的判断
            return;

        if(cards.size()==1)//只有一个元素 -> 判断是否为24
        {
            if(abs(cards[0]-24)<=num)
                flag=true;

            return;
        }

        for(int i=0;i<cards.size();i++)//控制取出来的第一个数字
        {
            for(int j=0;j<cards.size();j++)//控制取出来的第二个数字
            {
                if(i==j)
                    continue;//不能选择一样的
                
                //将选剩下的数填入数组中
                vector<double> arr;
                for(int k=0;k<cards.size();k++)
                {
                    if(k==i||k==j)
                        continue;
                    arr.push_back(cards[k]);
                }

                //将两个数的组合，填入数组之中
                double add=cards[i]+cards[j];
                arr.push_back(add);
                dfs(arr,flag,num);
                arr.pop_back();

                double sub=cards[i]-cards[j];
                arr.push_back(sub);
                dfs(arr,flag,num);
                arr.pop_back();

                double mul=cards[i]*cards[j];
                arr.push_back(mul);
                dfs(arr,flag,num);
                arr.pop_back();

                if(cards[j]!=0)
                {
                    double div=cards[i]/cards[j];
                    arr.push_back(div);
                    dfs(arr,flag,num);
                    arr.pop_back();
                }    

            }
        }
    }

    bool judgePoint24(vector<int>& cards) {
        //每次取两个数字出来进行四种运算回溯

        double num=pow(10,-6);

        vector<double> arr;
        for(auto&e:cards)
        {
            arr.push_back(e);
        }

        bool flag=false;
        dfs(arr,flag,num);

        return flag;
    }
};