class Solution {
public:
      int dp[2516];
    int helper(int i,vector<int>&nums){
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
            ans=max(ans,helper(j,nums)+1);
            }
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,helper(i,nums));
        }
      return ans;     
    }
};