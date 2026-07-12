class Solution {
public:
  int dp[300][7516];
   int helper(int idx,int amount,vector<int>&coins){
           if(amount==0) return 1;
           if(idx<0) return 0;
         if(dp[idx][amount]!=-1) return dp[idx][amount];
         int ans=0;
         for(int k=0;k<=amount;k+=coins[idx]){
            ans+=helper(idx-1,amount-k,coins);
         }
         return dp[idx][amount]=ans;
   }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        int p=helper(n-1,amount,coins);
        return p;
    }
};