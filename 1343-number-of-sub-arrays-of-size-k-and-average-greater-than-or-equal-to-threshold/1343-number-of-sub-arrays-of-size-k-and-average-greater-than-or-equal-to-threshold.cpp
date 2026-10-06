class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int sum=0;
         int p;
        vector<int>res;
        if(n>=3){
            for(int i=0;i<k;i++){
                sum+=arr[i];
            }
        }
           p=sum/k;
        if(p>=threshold) res.push_back(p);
        int i=0;
        int j=k;
        while(j<n){
            sum=sum-arr[i]+arr[j];
            p=sum/k;
           if(p>=threshold){
            res.push_back(p);
         }
          j++;
          i++;
        }
        return res.size();
    }
};