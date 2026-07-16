class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n=nums.size();
        vector<long long>pref;
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(max<nums[i]){
                max=nums[i];
            }
            pref.push_back(__gcd(max,nums[i]));
        }
        sort(pref.begin(),pref.end());
        long long i=0;
        long long j=pref.size()-1;
        long long sum=0;
        while(i<j){
           sum=0ll+sum+(__gcd(pref[i],pref[j]));
           i++;
           j--;
            
        }
        return sum;
    }
};