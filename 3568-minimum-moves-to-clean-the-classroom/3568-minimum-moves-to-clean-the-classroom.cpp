class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int si = -1, sj = -1;
        unordered_map<int, int> litterIndex; // encoded cell -> bit index
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') {
                    si = i; sj = j;
                } else if (c == 'L') {
                    litterIndex[i * n + j] = litterIndex.size();
                }
            }
        }
        
        int L = litterIndex.size();
        if (L == 0) return 0;
        int fullMask = (1 << L) - 1;
        int E = energy + 1;
        int M = 1 << L;
        
        auto idx = [&](int i, int j, int e, int mask) {
            return ((i * n + j) * E + e) * M + mask;
        };
        
        vector<bool> visited(m * n * E * M, false);
        visited[idx(si, sj, energy, 0)] = true;
        
        // state: i, j, energyLeft, mask, moves
        queue<tuple<int,int,int,int,int>> q;
        q.push({si, sj, energy, 0, 0});
        
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while (!q.empty()) {
            auto [i, j, e, mask, moves] = q.front();
            q.pop();
            
            if (mask == fullMask) return moves;
            if (e == 0) continue;
            
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (classroom[ni][nj] == 'X') continue;
                
                int ne = e - 1;
                int nmask = mask;
                
                auto it = litterIndex.find(ni * n + nj);
                if (it != litterIndex.end()) {
                    nmask |= (1 << it->second);
                }
                
                if (classroom[ni][nj] == 'R') {
                    ne = energy;
                }
                
                int state = idx(ni, nj, ne, nmask);
                if (!visited[state]) {
                    visited[state] = true;
                    q.push({ni, nj, ne, nmask, moves + 1});
                }
            }
        }
        
        return -1;
    }
};