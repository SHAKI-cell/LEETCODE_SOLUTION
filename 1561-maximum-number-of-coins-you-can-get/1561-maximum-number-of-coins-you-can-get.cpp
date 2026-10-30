class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(begin(piles),end(piles));
        int sum=0;
        int b=0;
        int a=n-1;
        int me=n-2;
       while(b<me){
           sum+=piles[me];
            a=a-1;
            me=me-2;
            b++;
        }
        return sum;
    }
};