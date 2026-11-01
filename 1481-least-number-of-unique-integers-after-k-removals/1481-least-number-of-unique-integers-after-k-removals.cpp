class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
       priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &x:mp){
           pq.push(x.second);
        }
        while(!pq.empty()){
            int t1=pq.top();
            k-=t1;
            if(k<0){
                return pq.size();
            }
            pq.pop();

        }
        return 0;
    }
};