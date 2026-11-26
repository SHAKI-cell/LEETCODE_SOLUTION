class Solution {
public:
    bool canAliceWin(int n) {
        int j=1;
        int i=10;
        int count=0;
        while(i<=n){
            j++;
            n=n-i;
            if(n>=0){
                count++;
            } else{
                break;
            }
           i-=1;
        }
        if(count%2==0){
            return false;
        } 
        return true;

    }
};