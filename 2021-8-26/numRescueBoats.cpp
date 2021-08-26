class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //将最大和最小的组合在一起，如果不超过limit，就使用一艘船，否则大船需要独自适用于一艘

        int begin=0;
        int end=people.size()-1;
        int count=0;

        sort(people.begin(),people.end());
        while(begin<=end)
        {
            if(begin==end)
            {
                count++;
                break;
            }

            if(people[begin]+people[end]<=limit)
            {
                count++;
                begin++;
                end--;
            }
            else
            {
                count++;
                end--;
            }
        }
        return count;

    }
};