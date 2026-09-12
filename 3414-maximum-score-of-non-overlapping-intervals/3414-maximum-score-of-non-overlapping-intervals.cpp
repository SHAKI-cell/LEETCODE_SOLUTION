class Solution {
public:
    int n;
    vector<int> nextidx;

    struct Node {
        long long score = 0;
        vector<int> idxs;
    };

    vector<vector<Node>> dp;
    vector<vector<bool>> vis;

    int findnext(vector<vector<int>>& intervals, int end) {
        int l = 0, r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (intervals[mid][0] > end)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {

        if (k == 0 || i >= n)
            return Node();

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        // Skip
        Node skip = solve(intervals, i + 1, k);

        // Take
        int j = nextidx[i];

        Node temp = solve(intervals, j, k - 1);

        Node take;
        take.score = intervals[i][2] + temp.score;

        take.idxs = temp.idxs;
        take.idxs.push_back(intervals[i][3]);

        sort(take.idxs.begin(), take.idxs.end());

        // Compare
        if (take.score > skip.score) {
            dp[i][k] = take;
        }
        else if (take.score < skip.score) {
            dp[i][k] = skip;
        }
        else {
            // Same score -> lexicographically smaller indices
            if (take.idxs < skip.idxs)
                dp[i][k] = take;
            else
                dp[i][k] = skip;
        }

        return dp[i][k];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // Store original index
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        nextidx.resize(n);

        for (int i = 0; i < n; i++) {
            nextidx[i] = findnext(intervals, intervals[i][1]);
        }

        // DP
        dp.resize(n, vector<Node>(5));
        vis.resize(n, vector<bool>(5, false));

        Node ans = solve(intervals, 0, 4);

        return ans.idxs;
    }
};