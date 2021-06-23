class TripleInOne {
public:
    TripleInOne(int stackSize) {
        arr.resize(3*stackSize);
        sub1=0;
        sub2=stackSize;
        sub3=2*stackSize;
        size=stackSize;
    }
    
    void push(int stackNum, int value) {
        switch(stackNum)
        {
            case 0:
                if(sub1<size)
                    arr[sub1++]=value;
                break;
            case 1:
                if(sub2<2*size)
                    arr[sub2++]=value;
                break;
            case 2:
                if(sub3<3*size)
                    arr[sub3++]=value;
                break;
        }
    }
    
    int pop(int stackNum) {

         switch(stackNum)
        {
            case 0:
                if(sub1>0)
                {
                    sub1--;
                    return arr[sub1];
                }
                else
                    return -1;
                break;
            case 1:
                if(sub2>size)
                {
                    sub2--;
                    return arr[sub2];
                }
                else
                    return -1;
                break;
            case 2:
                if(sub3>2*size)
                {
                    sub3--;
                    return arr[sub3];
                }
                else
                    return -1;
                break;
        }
        return -1;
    }
    
    int peek(int stackNum) {
        switch(stackNum)
        {
            case 0:
                if(sub1>0)
                    return arr[sub1-1];
                return -1;
                break;
            case 1:
                if(sub2>size)
                    return arr[sub2-1];
                return -1;
                break;
            case 2:
                if(sub3>2*size)
                    return arr[sub3-1];
                return -1;
        }
         return -1;

    }
    
    bool isEmpty(int stackNum) {
       if(stackNum==0&&sub1==0)
        return true;

        if(stackNum==1&&sub2==size)
        return true;

        if(stackNum==2&&sub3==2*size)
        return true;

        return false;

    }
    vector<int> arr;
    int sub1;
    int sub2;
    int sub3;
    int size;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */