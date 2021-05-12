取手套

class Gloves {
public:
    int allright(int n,vector<int> left,vector<int> right)
    {
          int sum=0;
        for(int i=0;i<n;i++)
        {
            if(right[i]==0)
                sum+=left[i];//将左边对应的右边为0的位置手套全部取出来
        }
        sum+=1;//然后再多取一个
        
        
        //左边为0的->右边要全部取出来
       for(int i=0;i<n;i++)
       {
           if(left[i]==0)
           {
               sum+=right[i];
               right[i]=0;
           }
       }
        //然后在右边剩余的手套之中，如果是最后一种则只取一个,否则全部取完
        sort(right.begin(),right.end());
        int begin=0;
        int end=n-1;
        while(right[begin]==0)
            begin++;//将前面的0全部取出
        while(begin<end)
        {
            sum+=right[end];//将最大的全部取完
            end--;
        }
        //最后剩下的只取1个
        sum+=1;

        return sum;
    }
    int allleft(int n, vector<int> left, vector<int> right)
    {
        //左边全部取出，右边取出1个
         int sum=0;
        for(int i=0;i<n;i++)
        {
            if(left[i]==0)
                sum+=right[i];//将左边对应的右边为0的位置手套全部取出来
        }
        sum+=1;//然后再多取一个
        
        
        //左边为0的->右边要全部取出来
       for(int i=0;i<n;i++)
       {
           if(right[i]==0)
           {
               sum+=left[i];
               left[i]=0;
           }
       }
        //然后在右边剩余的手套之中，如果是最后一种则只取一个,否则全部取完
        sort(left.begin(),left.end());
        int begin=0;
        int end=n-1;
        while(left[begin]==0)
            begin++;//将前面的0全部取出
        while(begin<end)
        {
            sum+=left[end];//将最大的全部取完
            end--;
        }
        //最后剩下的只取1个
        sum+=1;

        return sum;
    }
    int findMinimum(int n, vector<int> left, vector<int> right) {
        //题意转换：在两个数组之中取出多少数，其中一定有配对的数组
        //左边：右边为0的，在左边数组之中全部取出来再+1 -> 保证在右边之中可以找到对应的匹配
        //右边：左边为0的肯定全部要取出来，然后最多的全部拿出来，最后剩下的一个取一个即可
   
        int sum1=allleft(n,left,right);
        int sum2=allright(n,left,right);
        return fmin(sum1,sum2);
        
    }
};