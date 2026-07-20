class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<int>>res(n,vector<int>(m));
           k%=(n*m);
           if(k==0) return grid;
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int row=(((i*m)+j+k)/m)%n;
                res[row][(j+k)%m]=grid[i][j];
            }
           }
           return res;
    }
};