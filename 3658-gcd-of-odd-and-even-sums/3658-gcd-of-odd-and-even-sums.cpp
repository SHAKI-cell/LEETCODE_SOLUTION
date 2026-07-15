class Solution {
public:
int gcd(int p1,int p2){
    if(p2==0) return p1;
    return gcd(p2,p1%p2);
}
    int gcdOfOddEvenSums(int n) {
        // if(n==1) return 1;
        int p1=n*(n+1);
        int t=2*n;
        int p2=(t*(t+1))/2-p1;
        int p3=gcd(p1,p2);
        return p3;
    }
};