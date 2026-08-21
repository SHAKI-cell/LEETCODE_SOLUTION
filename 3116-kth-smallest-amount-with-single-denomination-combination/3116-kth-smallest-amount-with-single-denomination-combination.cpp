class Solution {
public:
typedef long long ll;
ll countsmaller(ll mid,vector<int>&coins){
    ll correctCount=0;
    int n=coins.size();
    for(int e=1;e<=(1<<n)-1;e++){
        ll lcm=0;
        ll order=0;
        for(int i=0;i<n;i++){
            if(e &  (1<<i)){
                order++;
                if(lcm==0){
                    lcm=coins[i];
                } else{
                    lcm=lcm*coins[i]/gcd(lcm,coins[i]);
                }
            }
        }
        if(order%2==0){
            correctCount-=mid/lcm;
        } else{
            correctCount+=mid/lcm;
        }
    }
    return correctCount;
}
    long long findKthSmallest(vector<int>& coins, int k) {
        ll result=-1;
        ll l=1;
        ll r=(ll)(*max_element(begin(coins),end(coins)))*k;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(countsmaller(mid,coins)>=k){
                result=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return result;
    }
};