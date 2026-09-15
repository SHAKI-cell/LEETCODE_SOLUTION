class Solution {
public:
    bool ispali(string &s,int i,int j){
        int n=s.size();
       while(i<j){
          if(s[i]!=s[j]) return false;
           i++;
           j--;
       }
       return true;
    }
     int solve(string &s,int k,int i,int j,vector<vector<int>>&t){
        int n=s.size();
        if(k==1) return n;
        if(i>=n || j>=n) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(ispali(s,i,j)){
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
        vector<vector<int>>t(n+1,vector<int>(n+1));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ispali(s,i,j)){
                    int take=1+(j+k <=n  ? t[j+1][j+k]:0);
                    int grow=t[i][j+1];
                    int slide=t[i+1][j+1];
                    t[i][j]=max({take,grow,slide});
                }
                int grow=t[i][j+1];
                int slide=t[i+1][j+1];
              t[i][j]=max({t[i][j],grow,slide});
            }
        }
        return t[0][k-1];
    }
};