class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        //根据题意只需要判断，有没有阻碍者比人更先到达终点即可
        //即阻碍者直接先在终点等待即可

        int people=abs(target[0])+abs(target[1]);//一个人到达终点的步伐数

        for(auto&e:ghosts)
        {
            int min=abs(e[0]-target[0])+abs(e[1]-target[1]);
            if(min<=people)
                return false;
        }
        return true;
    }
};