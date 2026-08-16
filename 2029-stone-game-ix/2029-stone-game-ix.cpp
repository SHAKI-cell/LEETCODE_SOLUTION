class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
         int cnt1=0;
         int cnt2=0;
         int cnt3=0;
         for(int ele: stones){
            if(ele%3==0){
                cnt1++;
            } else if(ele%3==1){ 
                cnt2++;
            } else{
                cnt3++;
            }
         }
         if(cnt1%2==0){
            return cnt2>=1 && cnt3>=1;
         }
         return abs(cnt2-cnt3)>2;
    }
};