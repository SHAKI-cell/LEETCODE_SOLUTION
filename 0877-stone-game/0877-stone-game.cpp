class Solution {
public:
  int t[600][600];
     int solve(int i,int j,vector<int>&piles){
        if(i>j) return 0;;
        if(i==j) return piles[i];
        if(t[i][j]!=-1) return t[i][j];
        int t1=piles[i]+min(solve(i+2,j,piles),solve(i+1,j-1,piles));
        int t2=piles[j]+min(solve(i+1,j-1,piles),solve(i,j-2,piles));
        return t[i][j]=max(t1,t2);
     }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(t,-1,sizeof(t));
        int t1=solve(0,n-1,piles);;
        return t1;
    }
};