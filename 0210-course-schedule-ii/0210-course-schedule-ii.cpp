class Solution {
public:
      vector<int> topo(unordered_map<int,vector<int>>&adj,int n, vector<int>&ind) {
        queue<int>pq;
        vector<int>result;
        int cnt=0;
           for(int i=0;i<n;i++){
            if(ind[i]==0){
                result.push_back(i);
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
                       pq.push(v);
                       result.push_back(v);
                       cnt++;
                  }
               }
           }
         if(cnt==n){
            return result;
         }
         return {};
    }

    vector<int> findOrder(int numout, vector<vector<int>>& pre) {
         int n=pre.size();
        unordered_map<int,vector<int>>adj;
        vector<int>ind(numout,0);
        for(auto & x:pre){
            int u=x[0];
            int v=x[1];
            adj[v].push_back(u);
            ind[u]++;
        }
        return topo(adj,numout,ind);
    }
};