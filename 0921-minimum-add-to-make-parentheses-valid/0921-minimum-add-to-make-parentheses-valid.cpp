class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int open=0;
        int close=0;
        // for(int i=0;i<n;i++){
        //    if(s[i]=='(') open++;
        //    else close++;
        // }
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            } else if(s[i]==')' && open>0){
                open--;
            } else{
                close++;
            }
        }
        // int score=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='('){
        //         open++;
        //     } else{
        //         close++;
        //     }
        //     if(open==close){
        //         open=0;
        //         close=0;
        //     } else if(open>close){
        //         score+=(open-close);
        //         open=0;
        //         close=0;
        //     } else if(close>open) {
        //         score++;
        //         close=0;
        //         open=0;
        //     }
        // }
        if(open>close) return open+close;
       return close+open;
    }
};