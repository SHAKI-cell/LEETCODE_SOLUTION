class Solution {
public:
 char midchar='$';
 int halflen=0;
string res="";
 bool helper(string &curr,vector<int>&freq,string &target,int i,bool greater){
    if(curr.size()==halflen){
       string cand=curr;
       string righthalf=curr;
       reverse(begin(righthalf),end(righthalf));
       if(midchar!='$'){
          cand+=midchar;
       }
       cand+=righthalf;
       if(cand>target){
        res=cand;
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
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
             freq[s[i]-'a']++;
        }
        int oddcount=0;
        for(int c=0;c<26;c++){
            if(freq[c]%2==1){
               oddcount++;
               midchar=c+'a';
            }
        }
        if(oddcount>1){
            return "";
        }
        for(int c=0;c<26;c++){
            freq[c]/=2;
        }
         halflen=n/2;

        string curr;
        helper(curr,freq,target,0,false);
        return res;
    }
};