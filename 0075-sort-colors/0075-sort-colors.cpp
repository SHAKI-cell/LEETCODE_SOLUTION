class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int red=0;
        int wh=0;
        int bl=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) red++;
            else if(nums[i]==1) wh++;
            else bl++;
        }  
        for(int i=0;i<n;i++){
            if(red>0){
                nums[i]=0;
                red--;
            } else if(wh>0){
                nums[i]=1;
                wh--;
             } else{
                nums[i]=2;
             }
        }
    }
};