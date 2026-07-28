class Solution {
public:
   
    string smallestPalindrome(string s) {
        int n=s.size();
        string ans3="";
        if(n%2!=0){
            ans3=s[n/2];
        }
        string  ans="";
        string ans1="";
        for(int i=0;i<n/2;i++){
             ans+=s[i];
             ans1+=s[n-i-1];
        }
         sort(ans.begin(),ans.end());
         sort(ans1.begin(),ans1.end());
        reverse(ans1.begin(),ans1.end());
         if(n%2!=0) return ans+ans3+ans1;
       return ans+ans1;
    }
};