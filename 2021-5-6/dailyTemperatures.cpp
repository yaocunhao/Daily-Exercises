每日温度

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //从后面寻找是否有比前面高的数字

        vector<int> ret(T.size(),0);
        ret[T.size()-1]=0;
        for(int i=T.size()-1;i>=0;i--)//从后往前寻找
        {
            for(int j=i+1;j<T.size();j++)
            {
                if(T[j]>T[i])
                {
                    ret[i]=j-i;
                    break;
                }
                if(T[j]<=T[i])
                {
                    if(ret[j]==0)
                    break;//后面没有比这个数更大的数了
                    else
                    j=j+ret[j]-1;//直接来到这一天
                }
                    
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size(),0);
        stack<int> st;
        for(int i=0;i<T.size();i++)
        {
            if(st.empty()||T[i]<=T[st.top()])//栈为空或者小于栈顶元素时，下标入栈
                st.push(i);
            else//新来下标大于栈顶元素
            {
                while(!st.empty()&&T[i]>T[st.top()])
                {
                    ret[st.top()]=i-st.top();
                    st.pop();//出栈
                }
                st.push(i);
            }
        }
        return ret;
    }
};
链接：https://leetcode-cn.com/problems/daily-temperatures/solution/cong-qian-wang-hou-xun-zhao-by-ych9527-z1ks/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。