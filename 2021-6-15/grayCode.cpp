class Solution {
public:
    vector<int> grayCode(int n) {
    //n =3
    //000-> 0  001 -> 1 010->2 011->3 100->4 101->5 110->6 111-> 7 编码总长度为2^n
    
    // 以n==2为例
    // 0^0=0 1^0=1 2^1=3 3^1=2 
  
    vector<int> arr;

    for(int i=0;i<pow(2,n);i++)
    {
        arr.push_back(i^i>>1);
    }
        return arr;
    }
};