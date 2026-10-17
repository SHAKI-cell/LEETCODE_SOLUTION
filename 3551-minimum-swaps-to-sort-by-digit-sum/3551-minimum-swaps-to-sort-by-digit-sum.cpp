class Solution {
public:
    int helper(int n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        auto labda=[&] (int num1,int num2){
        int dsum1=helper(num1);
        int dsum2=helper(num2);
        if(dsum1!=dsum2){
            return dsum1<dsum2;
        }
        return num1<num2;
      };
       vector<int>nums1(nums);
      sort(begin(nums1),end(nums1),labda);
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
          mp[nums[i]]=i;
       }
      int swapcount=0;
      for(int i=0;i<n;i++){
         int excep=nums1[i];
         int curr=nums[i];
         if(excep==curr){
             continue;
         }
         int idx=mp[excep];
         nums[i]=excep;
         nums[idx]=curr;
         mp[excep]=i;
         mp[curr]=idx;
         swapcount++;
      }
      return swapcount;
    }
};