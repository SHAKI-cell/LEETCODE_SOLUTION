class Solution {
public:
   typedef long long ll;
    string fun(ll required,int length){
        string str;
        for(int digit=9;digit>=2;digit--){
            while(required%digit==0){
                str.push_back(digit+'0');
                required/=digit;
            }
        }
        while(str.length()<length){
            str.push_back('1');
        }
        reverse(begin(str),end(str));
        return str;
    }
    string smallestNumber(string num, long long t) {
        int n=num.length();
        ll temp=t;
        for(int primefact:{2,3,5,7}){
            while(temp%primefact==0){
                temp/=primefact;
            }

        }
        if(temp!=1){
            return "-1";
        }
          
         /// precompute remaining factor[i]=if we take i digit of num in my result,what factor remaing
         vector<ll>remainingfactor(n+1,t);
         for(int i=0;i<n;i++){
            int digit=num[i]-'0';
               if(digit==0){
                break;
               }
            remainingfactor[i+1]=remainingfactor[i]/gcd(remainingfactor[i],(ll)digit);
         }
         if(remainingfactor[n]==1){
            return num;
         }
         int zero=num.find('0');
         int zeroidx=n-1;
         if(zero!=-1) {
            zeroidx=zero;
         }
         for(int i=zeroidx;i>=0;i--){
            ll req=remainingfactor[i];
            int freeslot=n-i-1;
            for(int digit=(num[i]-'0')+1;digit<=9;digit++){
                ll fureq=req/gcd(req,(ll)digit);
                string suffix=fun(fureq,freeslot);
                if(suffix.length()==freeslot){
                    return num.substr(0,i)+char(digit+'0')+suffix;
                }
            }
         }
         return fun(t,n+1);

    }
};