class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long n=nums.size();
        sort(begin(nums),end(nums));
        long long currsum=0;
        long long ans=0;
        for(int i=0;i<n;i++){
             long long edge=nums[i];
             if(currsum>edge){
                ans=(currsum+edge);
             }
             currsum+=edge;
        }
        if(ans==0) return -1;
        return ans;
    }
};