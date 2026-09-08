#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll lower=1000;
        ll ans=0;
        while(lower<=n){
            ans+=(n-lower+1);
            lower=lower*1000;
        }
        return ans;
    }
};