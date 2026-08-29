class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>vec=nums;
        sort(vec.begin(),vec.end());
        int groupNum=0;
        unordered_map<int,int>mp;
        mp[vec[0]]=groupNum;
        unordered_map<int,list<int>>grouplist;
        grouplist[groupNum].push_back(vec[0]);
        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                groupNum+=1;
            }
            mp[vec[i]]=groupNum;
            grouplist[groupNum].push_back(vec[i]);
        }
        // build the answer;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int group=mp[num];
            // smallest available number in this group
            ans[i]=*grouplist[group].begin();
            grouplist[group].pop_front();
             
        }
        return ans;
    }
};