class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        vector<char>ans(n);
       for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(i==0) ans[i]='a';
            else if(ans[i-1]=='a') ans[i]='a';
            else return false; 
        } else{
             ans[i]='b';
        }
       }
       return true;
    }
};