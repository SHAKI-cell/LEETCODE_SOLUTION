class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(min>nums[i]){
                min=nums[i];
            }
        }
        int oper=0;
        for(int i=0;i<n;i++){
            oper+=(nums[i]-min);
        }
        return oper;
    }
};