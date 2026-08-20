class Solution {
public:
    int dp[10001];
   int helper(int n){
      if(n==0){
         return 0;
      }
      if(dp[n]!=-1) return dp[n];
      int sum=INT_MAX;
      for(int i=1;i*i<=n;i++){
           sum=min(sum,1+helper(n-i*i));
      }
     return dp[n]=sum;
   }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        int t=helper(n);
        return t;
    }
};