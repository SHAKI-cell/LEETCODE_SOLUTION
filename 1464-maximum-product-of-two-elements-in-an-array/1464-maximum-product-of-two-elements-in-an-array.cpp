class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int t=*max_element(begin(nums),end(nums));
        int t1=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==t){
              count++;
            } else {
             t1=max(t1,(nums[i]-1)*(t-1));
            }
        }
        if(count>1){
            t1=max(t1,(t-1)*(t-1));
        }
        return t1;
    }
};