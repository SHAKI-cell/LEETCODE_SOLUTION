class Solution {
public:
   int dp[2][101][101];
   int helper(int t1,vector<int>&piles,int i,int M){
    int n=piles.size();
      if(i>=n) return 0;
      int result=(t1==1) ? -1:INT_MAX;
      if(dp[t1][i][M]!=-1) return dp[t1][i][M];
      int stones=0;
      for(int x=1;x<=min(2*M,n-i);x++){
         stones+=piles[x+i-1];
         if(t1==1){
            result=max(result,stones+helper(0,piles,i+x,max(M,x)));
         } else{
            result=min(result,helper(1,piles,i+x,max(M,x)));
         }
      }
      return dp[t1][i][M]=result;
   }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        int t=helper(1,piles,0,1);
        return t;
    }
};