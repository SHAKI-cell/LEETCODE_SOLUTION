class Solution {
public:
int t[20][20];
    int solve(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(t[i][j]!=-1) return t[i][j];
        int t1=nums[i]-solve(i+1,j,nums);
        int t2=nums[j]-solve(i,j-1,nums);
        return t[i][j]=max(t1,t2);

    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,n-1,nums)>=0;
    }
};