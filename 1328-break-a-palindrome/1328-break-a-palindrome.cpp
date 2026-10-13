class Solution {
public:
    string breakPalindrome(string nums) {
        int n=nums.size();
         if(n==1){
            if(nums[0]=='a') return "";
            else return "";
         }
        for(int i=0;i<n/2;i++){
           if(nums[i]!='a'){
              nums[i]='a';
              return nums;
           }
        }
        nums[n-1]='b';
        return nums;

    }
};