class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans1;
        vector<int>ans2;
        if(n<2){
            return nums;
        }
        if(n>=2){
        ans1.push_back(nums[0]);
        ans2.push_back(nums[1]);
        }
        for(int i=2;i<n;i++){
            if(ans1[ans1.size()-1]>ans2[ans2.size()-1]){
                  ans1.push_back(nums[i]);
            } else{
                ans2.push_back(nums[i]);
            }
        }
        int n1=ans1.size();
        int n2=ans2.size();
        for(int i=0;i<n2;i++){
          ans1.push_back(ans2[i]);
        }
        return ans1;
    }
};