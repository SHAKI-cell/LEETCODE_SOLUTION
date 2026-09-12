class Solution {
public:
typedef pair<int,vector<int>>pq;
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,pq>mp;
        for(int i=0;i<n;i++){
           mp[nums[i]].first++;
           mp[nums[i]].second.push_back(i);
        }
        int cnt=0;
        for(auto &x:mp){
            int t1=x.second.first;
            if(t1==3){
               vector<int>ans=x.second.second;
                  int t2=ans[0];
                  int t3=ans[1];
                  int t4=ans[2];
                  if(t3-t2==t4-t3) cnt++;
               }
            }
        return cnt;
    }
};