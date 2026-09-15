class Solution {
public:
    vector<vector<bool>>ispalin;
     int solve(string &s,int k,int i,int j,vector<vector<int>>&t){
        int n=s.size();
        if(k==1) return n;
        if(i>=n || j>=n) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(ispalin[i][j]){
           int take=1+solve(s,k,j+1,j+k,t);
           int grow=solve(s,k,i,j+1,t);
           int slide=solve(s,k,i+1,j+1,t);
           return t[i][j]=max({take,grow,slide});
        }
       int  grow=solve(s,k,i,j+1,t);
       int slide =solve(s,k,i+1,j+1,t);
        return t[i][j]=max(grow,slide);
     }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        ispalin.assign(n+1,vector<bool>(n+1,false));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l<=n;i++){
                int j=i+l-1;
                if(i==j){
                    ispalin[i][j]=true;
                } else if(i+1==j){
                    ispalin[i][j]=(s[i]==s[j]);
                } else{
                    ispalin[i][j]=(s[i]==s[j]) && ispalin[i+1][j-1];
                }
            }
        }
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        return solve(s,k,0,k-1,t);
    }
};