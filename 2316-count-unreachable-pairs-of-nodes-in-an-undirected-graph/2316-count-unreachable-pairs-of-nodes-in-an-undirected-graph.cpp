class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void union1(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        // step2
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            union1(u, v);
        }
        // step 3 (map banalo for staring "parent(component)")
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int papaji=find(i); // parent reprensentattivee
            mp[papaji]++;
        }
        // step4 find result from map
        long long res=0;
        long long remaingnodes=n;
        for(auto &it:mp){
            // int papaji=it.first
            long long size=it.second;
             res+=(size)*(remaingnodes-size);
            remaingnodes-=size;
        }
        return res;
    }
};