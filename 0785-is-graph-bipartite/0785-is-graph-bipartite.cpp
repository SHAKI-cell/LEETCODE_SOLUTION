class Solution {
public:
   bool isbfs(vector<vector<int>>&graph,int curr,vector<int>&color,int currcolor){
       queue<int>pq;
       pq.push(curr);
       color[curr]=currcolor;
       while(!pq.empty()){
           int u=pq.front();
           pq.pop();
           for(int & v:graph[u]){
             if(color[v]==color[u]) return false;
             else if(color[v]==-1){
                color[v]=1-color[u];
                pq.push(v);
             }
           }
       }
       return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
              if(color[i]==-1){
                 if(isbfs(graph,i,color,1)==false){
                    return false;
                 }
              }
        }
        return true;
    }
};