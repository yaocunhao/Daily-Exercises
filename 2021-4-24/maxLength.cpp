给定一个数组arr，返回arr的最长无的重复子串的长度(无重复指的是所有数字都不相同)。
class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        deque<int> slide;
      int max=0;
      for(int i=0;i<arr.size();i++)
      {
        for(int j=0;j<slide.size();j++)
        {
          if(arr[i]==slide[j])//找到重复的
          {
            max=fmax(max,slide.size());//先记录下来
            slide.erase(slide.begin(),slide.begin()+j+1);//删除掉前面的
          }
        }
        slide.push_back(arr[i]);//入队
      }
      max=fmax(max,slide.size());//最后再判断一次
      return max;
    }
};
时间复杂度：遍历外围数组O(n),每次都需要遍历双端队列，当没有重复元素的时候，时间复杂度高达o(N^2)