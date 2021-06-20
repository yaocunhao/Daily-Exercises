class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //在前面和后面添加0，解决一些场景下的边界问题
        vector<int> copy(heights.begin(),heights.end());
        copy.insert(copy.begin(),0);
        copy.push_back(0);

        int max=0;
        for(int i=0;i<copy.size();i++)
        {
            //新来的元素，小于栈顶元素
            while(!st.empty()&&copy[i]<copy[st.top()])
            {
                int cur=st.top();
                st.pop();
                int left=st.top();
                max=fmax(max,(i-left-1)*copy[cur]);
            }
            st.push(i);
        }

        return max;
    }

    stack<int> st;
};