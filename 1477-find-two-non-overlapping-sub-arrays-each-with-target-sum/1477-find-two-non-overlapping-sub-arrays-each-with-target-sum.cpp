class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
       int n =arr.size();
       int currsum=0;
       vector<int>idx(n,INT_MAX);
       int res=INT_MAX;
       int best=INT_MAX;
       int i=0;
       int j=0;
       while(j<n){
          currsum += arr[j];
         while(i<j && currsum>target){
              currsum-=arr[i];
              i++;
         }
         if(currsum==target){
            int len=j-i+1;
            if(i>0 && idx[i-1]!=INT_MAX){
                res=min(res,len+idx[i-1]);
            }
            best=min(best,len);
         }
         idx[j]=best;
         j++;
       }
       return res==INT_MAX ? -1:res;
    }
};