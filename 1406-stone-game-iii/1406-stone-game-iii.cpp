class Solution {
public:
 int n;
 vector<int>t1;
   int solve(vector<int>& nums,int i){
    if(i>=n) return 0;
    if(t1[i]!=-1) return t1[i];
    int result=INT_MIN;
       result=max(result,nums[i]-solve(nums,i+1));
     if(i+1<n){
        result=max(result,nums[i+1]+nums[i]-solve(nums,i+2));
     }
     if(i+2<n){
        result=max(result,nums[i]+nums[i+1]+nums[i+2]-solve(nums,i+3));
     }
     return t1[i]=result;
   }
    string stoneGameIII(vector<int>& nums) {
         n=nums.size();
         t1.resize(n+1,-1);
         int t=solve(nums,0);
         if(t<0){
            return "Bob";
         } else if(t>0){
            return "Alice";
         } else{
         return "Tie";
         }
       
    }
};