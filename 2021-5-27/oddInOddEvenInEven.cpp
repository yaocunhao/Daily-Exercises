class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int end=len-1;
        int begin=0;
        int second=1;
        
        while(begin<len&&second<len)
        {
            if(arr[end]%2==0)
            {
                swap(arr[begin],arr[end]);
                begin+=2;
            }
            else
            {
                swap(arr[second],arr[end]);
                second+=2;
            }
        }
    }
};