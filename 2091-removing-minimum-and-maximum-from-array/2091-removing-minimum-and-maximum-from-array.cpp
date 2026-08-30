class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int idx1=-1;
        int idx2=-1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(mn>nums[i]){
                mn=nums[i];
                idx2=i;
            }
            if(mx<nums[i]){
                mx=nums[i];
                idx1=i;
            }
        }
        int t1=idx1;
        int t2=n-idx1;
        int t3=idx2;
        int t4=n-idx2;
        int p3;
        if(idx1<idx2){
            int t=t1+t4+1;
            int p1=t1+1+idx2-idx1;
            int p2=t4+idx2-idx1;
             p3=min({t,p1,p2});
        } else{
            int t=t3+t2+1;
            int p1=t3+1+idx1-idx2;
            int p2=t2+idx1-idx2;
            p3=min({t,p1,p2});
        }
        return p3;
    }
};