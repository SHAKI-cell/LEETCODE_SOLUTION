class Solution {
public:
   bool topobfs(unordered_map<int,vector<int>>&adj,int n,vector<int>&ind
   ){
        queue<int>pq;
        int cnt=0;
        for(int i=0;i<n;i++){
              if(ind[i]==0){
                cnt++;
                pq.push(i);
              }
        }
        while(!pq.empty()){
            int u=pq.front();
            pq.pop();
            for(auto &v:adj[u]){
                ind[v]--;
                if(ind[v]==0){
                    cnt++;
                    pq.push(v);
                }
            }
        }
        if(cnt==n) return true;
        return false;
   }
    bool canFinish(int numout, vector<vector<int>>& pre) {
        int n=pre.size();
        unordered_map<int,vector<int>>adj;
        vector<int>ind(numout,0);
        for(auto &rec:pre){
            int u=rec[0];
            int v=rec[1];
            adj[v].push_back(u);
            ind[u]++;
        }
        return topobfs(adj,numout,ind);
    }
};