class Solution {
public:
    long long maximumHappinessSum(vector<int>&nums, int k) {
        long long n=nums.size();
        long long sum=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        sum=pq.top();
        pq.pop();
        k--;
        long long count=1;
        while(!pq.empty() && k--){
            int t=pq.top();
            pq.pop();
            long long z=t-count;
            if(z>0){
                sum+=z;
            } else{
                break;
            }
            count++;
            // k--;
        }
    //    sort(begin(nums),end(nums));
    //    int count=0;
    //    int sum=0;
    //    int t=k-1;
    //    for(int i=n-1;i>=0;i--){
    //         if(k<=0) break;

    //         sum+=nums[i];
    //         k--;
    //    }
       return sum;
    }
};