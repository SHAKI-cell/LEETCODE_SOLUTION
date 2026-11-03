class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(max<nums[i]){
                max=nums[i];
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<max){
                nums[i]+=1;
                count++;
            }
            if(nums[i]==max) continue;
            else{
                while(nums[i]!=max){
                    nums[i]+=1;
                    count++;
                }
            }
        }
        return count;
    }
};