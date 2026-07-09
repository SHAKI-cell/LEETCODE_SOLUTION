class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int Mod=1e9+7;
        typedef long long ll;
        int n=s.size();
       
        vector<int>nonzero(n,0);
        vector<ll>numberupto(n,0);
        vector<ll>digitupto(n,0);
        vector<ll>pow(n+1,0);
        pow[0]=1;
        for(int i=1;i<=n-1;i++){
            pow[i]=(pow[i-1]*10ll)%Mod;
        }
        nonzero[0]=(s[0]!='0') ? 1:0;
       for(int i=1;i<=n-1;i++){
           int digit=s[i]-'0';
           if(digit!=0){
             nonzero[i]=nonzero[i-1]+1;
           } else {
              nonzero[i]=nonzero[i-1];
           }
       }
        numberupto[0]=s[0]-'0';
        for(int i=1;i<=n-1;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                numberupto[i]=((numberupto[i-1]*10ll)+digit)%Mod;
            } else{
                numberupto[i]=numberupto[i-1];
            }
        }
        digitupto[0]=s[0]-'0';
        for(int i=1;i<=n-1;i++){
          int digit=s[i]-'0';
          digitupto[i]=digitupto[i-1]+digit;
        }
         int m=queries.size();
         vector<int>result;
         for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ll sum=digitupto[r]-((l==0) ? 0:digitupto[l-1]);
            int k=nonzero[r]-((l==0) ?  0:nonzero[l-1]);
            ll left=((l==0) ? 0:numberupto[l-1]);
            ll x=(numberupto[r]-(left*pow[k])%Mod+Mod)%Mod;
            result.push_back(((sum%Mod)*(x%Mod))%Mod);
         }
        return result;
    }
};