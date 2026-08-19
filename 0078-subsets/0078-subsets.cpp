class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         int n=nums.size();
        int mask=(1<<n);
        vector<vector<int>>st;
        for(int i=0;i<mask;++i){
            vector<int>subset;
            for(int j=0;j<n;++j){
                if((i & (1<<j))!=0){
                    subset.push_back(nums[j]);
                }
            }
            st.push_back(subset);
        }
        return st;
    }
};