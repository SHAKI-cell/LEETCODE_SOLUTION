class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int cnt=0;
        string res="";
         while(j<n){
          if(s[j]=='1'){
              cnt++;
          }
          while(cnt>k || s[i]=='0'){
             if(s[i]=='1'){
                cnt--;
             }
             i++;
          }
           if(cnt==k){
             int  len=j-i+1;
               string temp=s.substr(i,len);
               if(res.empty() || res.size()>len || ((temp.size()==res.size()) && temp<res)){
                   res=temp;
               }
           }
           j++;
       }
       return res;
    }
};