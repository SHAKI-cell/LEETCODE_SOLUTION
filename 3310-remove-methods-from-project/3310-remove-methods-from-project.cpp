class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>ind(n,0);
        vector<bool>sus(n,false);
        for(auto &edge:invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            ind[v]++;
        }
        queue<int>pq;
        pq.push(k);
        sus[k]=true;
        while(!pq.empty()){
            int curr=pq.front();
            pq.pop();
            for(int &ndgr : adj[curr]){
                ind[ndgr]--;
                if(!sus[ndgr]){
                    pq.push(ndgr);
                    sus[ndgr]=true;
                }
            }
        }
        vector<int>res;
        bool cnr=false;
        for(int i=0;i<n;i++){
            if(sus[i] && ind[i]>0){
                cnr=true;
                break;
            }
            if(!sus[i]){
                res.push_back(i);
            }
        }
        if(cnr){
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return res;
        
    }
};