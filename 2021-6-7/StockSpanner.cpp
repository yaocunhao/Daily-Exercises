class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
 
         int sum=1;
        while(!val.empty()&&price>=val.top())
        {
            sum+=count.top();
            count.pop();
            val.pop();
        }
            
        val.push(price);
        count.push(sum);
        
        return count.top();
    }
    stack<int> val;
    stack<int> count; 
};
