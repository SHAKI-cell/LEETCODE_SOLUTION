class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(is_sorted(begin(s),end(s))){
             return 0;
        }
        if(n==2) return -1;
      char min_char=*min_element(begin(s),end(s));
      char max_char=*max_element(begin(s),end(s));
       if(s[0]==min_char){
        return 1;
       }
       if(s[n-1]==max_char){
        return 1;
       }
       char max_middle=*max_element(begin(s)+1,end(s)-1);
       char min_middle=*min_element(begin(s)+1,end(s)-1);
       if(s[0]>max_middle && s[n-1]<min_middle){
        return 3;
       }
       return 2;
    }
};