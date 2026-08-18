class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
         unordered_map<int,int>mp;
        for(int i=0;i<=n-k;i++){
            unordered_map<int,bool>seen;
           for(int j=i;j<i+k && j<n;j++){
              if(!seen[nums[j]]){
               mp[nums[j]]++;
               seen[nums[j]]=true;
           }
        }
        }
      int ans=-1;
      for(auto &x:mp){
        if(x.second==1){
            ans=max(ans,x.first);
        }
      }
      return ans;
    }
};