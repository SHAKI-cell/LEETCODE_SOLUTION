class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       int n=arr.size();
       vector<int>ans=arr;
       sort(ans.begin(),ans.end());
       ans.erase(unique(ans.begin(),ans.end()),ans.end());
       unordered_map<int,int>mp;
       for(int i=0;i<ans.size();i++){
           mp[ans[i]]=i;
       }
       for(int i=0;i<n;i++){
         arr[i]=mp[arr[i]]+1;
       }
       return arr;
    }
};