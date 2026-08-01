class Solution {
public:
int t[20][20];
    int solve(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(t[i][j]!=-1) return t[i][j];
        int t1=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int t2=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return t[i][j]=max(t1,t2);

    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
       int sum=0;
        for(int i=0;i<n;i++){
             sum+=nums[i];
        }
      int t1=solve(0,n-1,nums);
      int t2=sum-t1;
        return t1>=t2;
    }
};