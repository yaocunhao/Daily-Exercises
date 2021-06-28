class Solution {
public:
    bool find(unordered_map<int,vector<int>>&record,int n,int k)
    {
        vector<int> ve=record[n];
        for(int i=0;i<ve.size();i++)
        {
            if(ve[i]==k)
                return false;
        }

        record[n].push_back(k);
        return true;
    }
    bool canCross(vector<int>& stones) {
        //注意点：跳到同样的位置，但是上一步的跳跃距离不一样

        vector<int> arr(2,0);//记录当前的位置，和上一次跳的步伐
        
        unordered_set<int> st;//记录石头编号
        for(auto&e:stones)
        {
            st.insert(e);
        }

        if(st.find(stones[0]+1)==st.end())//第一步就，跳到了水中
            return false;
        if(stones.size()==2)//只有两块石头,就到达了
            return true;

        arr[0]=stones[0]+1;//当前位置
        arr[1]=1;//上一跳的距离 

        queue<vector<int>> qe;
        unordered_map<int,vector<int>> record;//记录到达的石块
        qe.push(arr);
        record[arr[0]].push_back(1);
        while(!qe.empty())
        {
            vector<int> ve=qe.front();
            qe.pop();

            if(ve[0]==*(--stones.end()))//跳到了最后一个位置
                return true;

            int k=ve[1];//上一跳的距离
            int jump1=ve[0]+k-1;
            int jump2=ve[0]+k;
            int jump3=ve[0]+k+1;

            if(jump1>0&&st.find(jump1)!=st.end()&&find(record,jump2,k-1))
            {
                vector<int> temp;
                temp.push_back(jump1);
                temp.push_back(k-1);
                qe.push(temp);
            }
              if(jump2>0&&st.find(jump2)!=st.end()&&find(record,jump2,k))
            {
                vector<int> temp;
                temp.push_back(jump2);
                temp.push_back(k);
                qe.push(temp);
            }
              if(jump3>0&&st.find(jump3)!=st.end()&&find(record,jump2,k+1))
            {
                vector<int> temp;
                temp.push_back(jump3);
                temp.push_back(k+1);
                qe.push(temp);
            }
        }
        return false;
    }
};