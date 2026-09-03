class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
         int t=*min_element(nums1.begin(),nums1.end());
         int odd=0,eve=0;
         for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
               eve++;
            } else{
                odd++;
            }
         }
         if(eve==0) return true;
         if(odd==0) return true;
          if(t%2==0){
            for(int i=0;i<n;i++){
                if(nums1[i]%2==1){
                    nums1[i]=nums1[i]-t;
                }
            }
            } else{
               for(int i=0;i<n;i++){
                   if(nums1[i]%2==0){
                    nums1[i]=nums1[i]-t;
                   }
               }
            }
          int odd1=0;
          int eve1=0;
          for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                eve1++;
            } else{
                odd1++;
            }
          }
          if(eve1==0) return true;
         if(odd1==0) return true;
         return false;
    }
};