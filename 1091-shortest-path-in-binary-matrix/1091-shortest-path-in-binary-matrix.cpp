class Solution {
public:
typedef pair<int,pair<int,int>>p;
vector<vector<int>>dir{{1,1},{0,1},{1,0},{-1,1},{-1,-1},{0,-1},{-1,0},{1,-1}};
 int n,m;
   bool issafe(int x,int y){
      if(x>=0 && x<m && y>=0 && y<n) return true;
      return false;
   }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         n=grid.size();
        m=grid[0].size();
        if(m==0 || n==0 || grid[0][0]==1) return -1;
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
          res[0][0]=0;
          while(!pq.empty()){
              int d1=pq.top().first;
            pair<int,int> node=pq.top().second;
              int x=node.first;
              int y=node.second;
              pq.pop();
              for(auto d:dir){
                int x_=x+d[0];
                int y_=y+d[1];
                int dist=1;
                if(issafe(x_,y_) && grid[x_][y_]==0 && d1+dist < res[x_][y_]){
                    pq.push({d1+dist,{x_,y_}});
                    res[x_][y_]=d1+dist;
                }
              }
          }
          if(res[m-1][n-1]==INT_MAX){
             return -1;
          }
          return res[m-1][n-1]+1;
    }
};