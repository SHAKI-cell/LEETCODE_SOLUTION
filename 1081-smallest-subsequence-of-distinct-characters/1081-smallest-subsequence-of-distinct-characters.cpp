class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
       string result;
       vector<bool>taken(26,false);
       vector<int>previdx(26);
       for(int i=0;i<n;i++){
         char ch=s[i];
         previdx[ch-'a']=i;
       }
       for(int i=0;i<n;i++){
           char ch=s[i];
           int idx=ch-'a';
           if(taken[idx]==true) continue;
           else{
            while(result.size()>0 && result.back()>ch && previdx[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[idx]=true;
           }
       }
       return result;
    }
};