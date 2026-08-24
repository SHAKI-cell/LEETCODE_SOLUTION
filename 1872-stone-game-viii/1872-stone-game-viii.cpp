class Solution {
public:
   
    int stoneGameVIII(vector<int>& stones) {
        int  n=stones.size();
        vector<int>pref(n,0);
        pref[0]=stones[0];
        for(int i=1;i<n;i++){
           pref[i]=stones[i]+pref[i-1];
        }
        vector<int>t(n,0);
        t[n-1]=pref[n-1];
        for(int i=n-2;i>=1;i--){
            int take=pref[i]-t[i+1];
            int skip=t[i+1];
            t[i]=max(take,skip);
        }
        // vector<int>ans;
        // idx=-1;
        // for(int i=n-1;i>=0;i--){
        //     if(pre[i]>0){
        //         ans.push_back(pref[i]);
        //         idx=i;
        //         for(int j=idx;j<n;j++){
        //             ans.push_back(stones[j]);
        //         }
        //     }
        // }t[1]
        return t[1];
        
    }
};