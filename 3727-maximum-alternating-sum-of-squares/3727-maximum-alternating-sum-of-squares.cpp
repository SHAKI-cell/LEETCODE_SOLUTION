class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n=nums.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(abs(nums[i]));
        }
        priority_queue<int,vector<int>,greater<int>>pq1;
        for(int i=0;i<n;i++){
            pq1.push(abs(nums[i]));
        }
        vector<int>ans;
       int i=0;
       while(i<n){
        if(i<n){
            i++;
         int t1=pq.top();
         pq.pop();
         ans.push_back(t1);
        }
        if(i<n){
         int t2=pq1.top();
         pq1.pop();
         i++;
         ans.push_back(t2);
       }
       }
       long long sum=0;
       for(int i=0;i<ans.size();i++){
        if(i%2==0) sum+=ans[i]*ans[i];
        else sum-=ans[i]*ans[i];
       }


      return sum;



        // vector<int>pref(n+1,0);
        // if(n==1) return nums[0]*nums[0];
        //  if(n>1) pref[0]=max(nums[0],nums[1]);
        // for(int i=1;i<=n-1;i++){
        //     if(i%2!=0){
        //         if(nums[i]>=0){
        //     pref[i]=min(nums[i],nums[i-1]);
        //         } else{
        //         pref[i]=max(nums[i],nums[i-1]);
        //         }
        //     } else{
        //       if(nums[i]>0) pref[i]=max(nums[i],nums[i-1]);
        //       else pref[i]=min(nums[i],nums[i-1]);
        //     }
        // }
        // long long sum=0;
        // for(int i=0;i<pref.size();i++){
        //     if(i%2==0){
        //         sum+=pref[i]*pref[i];
        //     } else{
        //         sum-=pref[i]*pref[i];
        //     }
        // }
        // return sum;
    }
};