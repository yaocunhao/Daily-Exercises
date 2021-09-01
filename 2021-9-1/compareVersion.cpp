class Solution {
public:
    int compareVersion(string version1, string version2) {
        //根据.号来分割字符串，然后比较每一段点号中数字的大小即可

        int sub1=0;
        int sub2=0;
        while(sub1<version1.size() || sub2 < version2.size())
        {
            int num1=0;
            int curry=1;
            while(sub1<version1.size() && version1[sub1]!='.')
            {
                num1*=curry;
                num1+=(version1[sub1]-'0');

                if(num1!=0)
                    curry*=10;
                
                sub1++;
            }
            sub1++;//跳过.号

            int num2=0;
            int curry2=1;
            while(sub2<version2.size() && version2[sub2]!='.')
            {
                num2*=curry2;
                num2+=(version2[sub2]-'0');

                if(num2!=0)
                    curry2*=10;

                sub2++;
            }
            sub2++;

            if(num1<num2)
                return -1;
            else if(num1>num2)
                return 1;
        }
        return 0;
    }
};