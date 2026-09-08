class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long lower=1000;
        int com=1;
        while(lower<=n){
            long long end=lower*1000-1;
             if(end>n) end=n;
            long long countno=(end-lower+1);
             ans+=(countno*com);
             lower=lower*1000;
             com++;
        }
        return ans;
    }
};