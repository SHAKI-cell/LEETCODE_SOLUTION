class Solution {
public:
    int minDeletions(string s) {
     int n=s.size();
     int freq[26]={0};
     for(auto &x:s){
        freq[x-'a']++;
     }
     sort(begin(freq),end(freq));
     int result=0;
      for(int i=24;i>=0 && freq[i]>0;i--){
          if(freq[i]>=freq[i+1]){
            int prev=freq[i];
            freq[i]=max(0,freq[i+1]-1);
            result+=(prev-freq[i]);
          }
       }
       return result;
    }
};