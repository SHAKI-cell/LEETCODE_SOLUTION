class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
      int n=nums.size();
       int t=0;
       bool allele=true;
       for(int &x:nums){
        t=t ^ x;
          if(x!=0){ // atleast one element should be not zero . so allele=false
            allele=false;
          }
       }
       if(allele){
           return 0;
       }
       return (t==0) ? n-1:n;
    }
};