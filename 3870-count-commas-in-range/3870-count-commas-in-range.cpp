class Solution {
public:
    int countCommas(int n) {
        int cnt=0;
        int p=n;
        while(n!=0){
            // if(cnt>=4) break;
           cnt++;
           if(cnt>=4) break;
           n/=10;
        }
        int t;
        if(cnt>=4){
        if(1000<=p<10000){
             t=p-1000;
        } else if(10000<=p<100000){
            t=p-1000;
        } else{
            t=p-100000;
        }
        } else{
            return 0;
        }
        return t+1;
    }
};