class Solution {
public:
  int n,m;
  typedef pair<int,pair<int,int>>pi;
  vector<vector<int>>dr{{-1,0},{1,0},{0,-1},{0,1}};
    int minimumEffortPath(vector<vector<int>>& height) {
        n=height.size();
        m=height[0].size();
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        auto issafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int t=pq.top().first;
            auto t1=pq.top().second;
            pq.pop();
            int x=t1.first;
            int y=t1.second;
            for(auto &dir:dr){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(issafe(x_,y_)){
                    int absdiff=abs(height[x][y]-height[x_][y_]);
                    int maxdiff=max(t,absdiff);
                    if(result[x_][y_]>maxdiff){
                        result[x_][y_]=maxdiff;
                        pq.push({maxdiff,{x_,y_}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};