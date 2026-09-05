class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suff(n),pref(n);
        suff[0]=nums[0];
        for(int i=1;i<n;i++){
          suff[i]=max(suff[i-1],nums[i]);
        }
        pref[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pref[i]=min(pref[i+1],nums[i]);
        }
       int  idx=-1;
        for(int i=0;i<n;i++){
            int t=suff[i]-pref[i];
            if(t>k) continue;
            else{
               idx=i;
               break;
            }
        }
        return idx;
    }
};