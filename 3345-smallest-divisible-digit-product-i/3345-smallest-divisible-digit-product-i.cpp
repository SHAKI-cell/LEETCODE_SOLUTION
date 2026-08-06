class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
           int p=i;
           int sum=0;
           int t1=1;
           while(p!=0){
              t1=t1*(p%10);
              p/=10;
           }
           if(t1%t==0) return i;
        }
        return 0;
    }
};