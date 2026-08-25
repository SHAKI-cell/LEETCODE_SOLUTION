class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
         if(nums[i]%k==0){
            mp[nums[i]]++;
         }
       }
       int i=1;
        while(1){
            int t1=k*i;
            if(mp[t1]<1){
                return t1;
            }
            i++;
        }
        return 0;
    }
};