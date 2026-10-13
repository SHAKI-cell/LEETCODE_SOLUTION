class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        int count=0;
        bool flag=false;
       for(string &i:words){
           string t=i;
           reverse(t.begin(),t.end());
           if(t!=i){
            if(mp[i]>0 && mp[t]>0){
                mp[i]--;
                mp[t]--;
               count+=4;
            }
          } else{
              if(mp[i]>=2){
                mp[i]-=2;
                 count+=4;
              } else if(mp[i]==1 && flag==false){
                mp[i]--;
                count+=2;
                flag=true;
              }
            }
          }
       return count;
    }
};