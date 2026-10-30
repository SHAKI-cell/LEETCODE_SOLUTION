class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int oper=0;
        for(auto &x:mp){
            int t1=x.second;
            if(t1==1) return -1;
            oper+=ceil((double)t1/3);
        }
        return oper;
    }
};