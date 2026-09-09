class Solution {
public:
int n,m;
vector<vector<int>>dir{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
bool issafe(int x,int y){
     if(x>=0 && x<n && y>=0 && y<n) return true;
     return false; 
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
       if(m==0 || n==0 ||  grid[0][0]!=0) return -1;
       queue<pair<int,int>>pq;
       pq.push({0,0});
       grid[0][0]=1;
       int level=0;
       while(!pq.empty()){
          int N=pq.size();
          while(N--){
            auto curr=pq.front();
            pq.pop();
            int x=curr.first;
            int y=curr.second;
            if(x==m-1 && y==n-1) return level+1;
             for(auto d:dir){
                int x_=x+d[0];
                int y_=y+d[1];
                if(issafe(x_,y_) &&  grid[x_][y_]==0){
                    pq.push({x_,y_});
                    grid[x_][y_]=1;
                }
             }

          }
          level++;
       }
       return -1;
    }
};