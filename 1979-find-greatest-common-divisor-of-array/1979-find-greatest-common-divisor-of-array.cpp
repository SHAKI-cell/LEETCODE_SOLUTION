class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN;
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(max<nums[i]){
                 max=nums[i];
            }
            if(min>nums[i]){
                min=nums[i];
            }
        }
        return __gcd(max,min);
    }
};