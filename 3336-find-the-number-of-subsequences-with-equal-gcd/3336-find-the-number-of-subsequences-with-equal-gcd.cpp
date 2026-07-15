class Solution {
public:
    int  MOD=1e9+7;
    int t[201][201][201];
    int helper(vector<int>&nums,int i,int first,int second){
         if(i==nums.size()){
            bool nonempty=(first!=0 && second!=0);
            bool gcdmatch=(first==second);
            return (nonempty && gcdmatch) ? 1:0;
         }
         if(t[i][first][second]!=-1) return t[i][first][second];
        int skip=helper(nums,i+1,first,second);
        int first1=helper(nums,i+1,__gcd(first,nums[i]),second);
        int second1=helper(nums,i+1,first,__gcd(second,nums[i]));
        return t[i][first][second]=(0ll+skip+first1+second1)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return helper(nums,0,0,0);
    }
};