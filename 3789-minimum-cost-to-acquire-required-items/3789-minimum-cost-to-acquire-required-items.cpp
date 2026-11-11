class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long  total=0;
        if(cost1+cost2<=costBoth){
         long long t=(long long)((long long)cost1*need1+(long long)cost2*need2);
         return t;
        }
        long long both=min(need1,need2);
         total+=both*(long long)costBoth;
         need1-=both;
         need2-=both;
         if(need1>0){
            total+=(long long)need1*min(cost1,costBoth);
         } else if(need2>0){
            total+=(long long)need2*min(cost2,costBoth);
         }
        return total;
    }
};