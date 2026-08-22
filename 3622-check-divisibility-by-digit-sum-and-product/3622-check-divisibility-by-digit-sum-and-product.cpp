class Solution {
public:
    bool checkDivisibility(int n) {
        int r=n;
        int sum=0;
        int p=1;
        while(n!=0){
            int t=n%10;
            sum+=t;
            p=p*t;
            n/=10;
        }
        int t1=p+sum;
        if(r%t1==0){
            return true;
        }
        return false;
    }
};