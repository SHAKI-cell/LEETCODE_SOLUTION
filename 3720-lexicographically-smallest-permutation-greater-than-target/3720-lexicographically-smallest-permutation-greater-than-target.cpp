class Solution {
public:
string res="";
  bool helper(string &curr,vector<int>&freq,string &target,int i,bool greater){
      if(i==target.size()){
        if(greater){
            res=curr;
            return true;
        }
        return false;
      }
      for(char ch='a';ch<='z';ch++){
          if(freq[ch-'a']==0) continue;
          if(greater==false && ch<target[i]){
              continue;
          }
          curr.push_back(ch);
          freq[ch-'a']--;
          bool isgreater=greater || ch>target[i];
          if(helper(curr,freq,target,i+1,isgreater)){
             return true;
          }
          curr.pop_back();
          freq[ch-'a']++;
      }
      return false;
  }
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>freq(26,0);
        for(char &ch:s){
           freq[ch-'a']++;
        }
        string curr;
        bool t=helper(curr,freq,target,0,false);
        return res;
    }
};