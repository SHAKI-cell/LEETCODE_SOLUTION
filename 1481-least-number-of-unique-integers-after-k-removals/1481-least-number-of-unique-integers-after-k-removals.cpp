class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int>freq;
        int count=0;
        for(auto &x:mp){
           freq.push_back(x.second);
        }
       sort(begin(freq),end(freq));
       for(int i=0;i<freq.size();i++){
           k-=freq[i];
           if(k<0){
             return freq.size()-i;
           }
       }
       return 0;
    }
};