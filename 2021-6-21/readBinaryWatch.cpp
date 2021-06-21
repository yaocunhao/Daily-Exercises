class Solution {
public:
    void Watchminute(vector<string>& ret,int hours,int minute,int count,int num,int sub)
    {
        if(minute>59||count>num)//时间超了
            return;
        if(count==num)//灯数量到了
        {
            //将对应的时间保存起来
            string temp;
            temp+=to_string(hours);
            temp+=":";
            if(minute<10)
            {
                temp+=to_string(0);
            }
            temp+=to_string(minute);
            ret.push_back(temp);
            return;
        }
        for(int i=sub;i<=32;i+=i)
        {
            minute+=i;//时间增加
            count++;//灯数量增加
            Watchminute(ret,hours,minute,count,num,sub+=sub);//sub+=sub相同的灯只可出现一次
            minute-=i;
            count--;
        }
    }
    void Watchhours(vector<string>&ret,int hours,int count,int num,int sub)
    {
        if(count>num||hours>11||num==0)//灯的数量超了或者小时数超了
            return;
        
        Watchminute(ret,hours,0,0,num-count,1);

        for(int i=sub;i<=8;i+=i)
        {
            count++;//灯数量计数器
            hours+=i;
            Watchhours(ret,hours,count,num,sub+=sub);
            hours-=i;
            count--;
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        //整数，表示亮着的LED数量，所有可能的时间
        //一个灯表示的小时: 1 2 4 8 
        //一个灯表示的分钟:1 2 4 8 16 32  -> 循环从1开始，每次翻倍自身

        int num=0;
        vector<string> ret;
        if(turnedOn==0)
        {
            string temp("0:00");
            ret.push_back(temp);
            return ret;
        }
        Watchhours(ret,0,0,turnedOn,1);
        return ret;
    }
};