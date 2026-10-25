class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
      int n=nums.size();
      int i=k;
      int j=k;
      int currmin=nums[k];
      int result=nums[k];
      while( i>0 || j<n-1){
        int leftvalue=(i>0) ? nums[i-1]:0;
        int rightvalue=(j<n-1) ? nums[j+1]:0;
        if(leftvalue>rightvalue){
            i--;
            currmin=min(currmin,nums[i]);
        } else{
           j++;
           currmin=min(currmin,nums[j]);
        }
        result=max(result,currmin*(j-i+1));
      }
      return result;
    }
};