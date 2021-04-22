11. 盛最多水的容器

class Solution {
public:
    int maxArea(vector<int>& height) {
        //给定两个指针，分别指向左右两边
        //如果，记录当前的容量，然后让小的指针往中间移动，再计算容量大小
        //为什么移动小的呢？
        //这是因为，如果移动大的变，移动的时候，底肯定是减少的，而高，肯定是小于等于较小边的，因此
        //如果移动大边，容量必定减少

        int max=0;
        int left=0;
        int right=height.size()-1;
        while(left<right)
        {
            int min_height=fmin(height[left],height[right]);//取得较小边

            max=fmax(max,(right-left)*min_height);

            if(height[left]==min_height)
                left++;
            else
                right--;
        }
        return max;

    }
};