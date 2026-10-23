class Solution {
public:
    int minDeletions(string s) {
      int n=s.size();
      int freq[26]={0};
      for(char &x:s){
        freq[x-'a']++;
      }
      int result=0;
      unordered_set<int>st;
      for(int i=0;i<26;i++){
        while(freq[i]>0 && st.find(freq[i])!=st.end()){
            freq[i]--;
            result++;
        }
        st.insert(freq[i]);
      }
      return result;
      
    }
};