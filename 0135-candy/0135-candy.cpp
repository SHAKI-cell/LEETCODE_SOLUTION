class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int>count(n,1);
        for(int i=1;i<=n-1;i++){
          if(nums[i]>nums[i-1]){
            count[i]=max(count[i],count[i-1]+1);
          }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
               count[i]=max(count[i],count[i+1]+1);
            }
        }
        int result=0;
        for(int i=0;i<n;i++){
           result+=count[i];
        }
        return result;
    }
};