class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        int j=1;
        int p;
       for(int i=0;i<n;i++){
        int t=s[i]-'a';
         int  t1=26-t;
           p=t1*j;
           sum+=p;
           j++;
       }
       return sum;
    }
};