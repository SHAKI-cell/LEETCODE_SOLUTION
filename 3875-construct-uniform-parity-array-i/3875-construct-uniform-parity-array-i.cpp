class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>ans(n);
        int eve=0;
        int odd=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                eve++;
            } else{
                odd++;
            }
        }
        if(odd==0) return true;
         if(eve==0) return true;
         if(odd==eve) return true;
           for(int i=0;i<n-1;i++){
              ans[i]=nums1[i]-nums1[i+1];
           if(ans[i]%2==0){
               if(nums1[i+1]%2==0){
                  ans[i]=nums1[i+1];
               } else{
                if(i+2<n){
                    ans[i+1]=nums1[i+1]-nums1[i+2];
                } else{
                    ans[i+1]=nums1[i+1];
                }
               }
           } else{
              if(nums1[i+1]%2==0){
                if(i+2<n){
                  ans[i+1]=nums1[i+1]-nums1[i+2];
                } else{
                    ans[i+1]=nums1[i+1];
                }
              } else{
                  ans[i+1]=nums1[i+1];
              }
           }
        }
        return true;
    }
};