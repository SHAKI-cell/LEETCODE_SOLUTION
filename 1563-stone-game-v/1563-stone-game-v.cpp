class Solution {
public:
int t[501][501];
    int solve(int i,int j,vector<int>&curr){
        if(i>=j) return 0;
        int  sum=0;
        if(t[i][j]!=-1) return t[i][j];
        for(int mid=i;mid<=j-1;mid++){
            int leftsum=curr[mid]-(i-1>=0 ? curr[i-1]:0);
            int rightsum=curr[j]-curr[mid];
            if(leftsum<rightsum){
                sum=max(sum,leftsum+solve(i,mid,curr));
            } else if(leftsum> rightsum){
                sum=max(sum,rightsum+solve(mid+1,j,curr));
            } else {
                  sum=max({sum,leftsum+solve(i,mid,curr),rightsum+solve(mid+1,j,curr)});
            }
        }
        return t[i][j]=sum;
    }
    int stoneGameV(vector<int>& stone) {
        int n=stone.size();
        memset(t,-1,sizeof(t));
        vector<int>curr(n,0);
        curr[0]=stone[0];
        for(int i=1;i<n;i++){
            curr[i]=curr[i-1]+stone[i];
        }
        return solve(0,n-1,curr);
    }
};