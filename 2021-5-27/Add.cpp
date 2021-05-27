class Solution {
public:
    int Add(int num1, int num2) {
        int count=0;
        while(num1--)
        {
            count++;
        }
        
        while(num2--)
        {
            count++;
        }
        
        return count;

    }
};