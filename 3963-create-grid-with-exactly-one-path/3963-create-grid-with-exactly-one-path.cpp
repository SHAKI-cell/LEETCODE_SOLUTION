class Solution {
public:
bool dfs(int i,int j,vector<string>&ans,int m,int n){
     if(i==m-1 && j==n-1){
         ans[i][j]='.';
         return true;
     }
     ans[i][j]='.';
     if(j<n-1 && dfs(i,j+1,ans,m,n)){
         return true;
     }
     if(i<m-1 && dfs(i+1,j,ans,m,n)){
        return true;
     }
     ans[i][j]='#';
     return false;

}
    vector<string> createGrid(int m, int n) {
       vector<string>ans(m,string(n,'#'));
        dfs(0,0,ans,m,n);
        return ans;
    }
};