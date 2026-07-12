class Solution {
public:
 int helper(int i,vector<vector<int>>&dp,int cost){
     if(cost==0) return 1;
     if(cost<0) return 0;
     if(dp[i][cost]!=-1) return dp[i][cost];
       int ans=0;
        ans+=helper(i+1,dp,cost-1);
        ans+=helper(i+1,dp,cost-2);
      return   dp[i][cost]=ans;
 }
    int climbStairs(int n) {
       vector<vector<int>>dp(n+2,vector<int>(n+1,-1));
       int p=helper(0,dp,n);
       return p;
    }
};