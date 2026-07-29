class Solution {
public:
    long long ncr(int n,int r,long long k){
        r=min(r,n-r);
        long long result=1;
        for(int i=1;i<=r;i++){
            result=result*(n-r+i)/i;
            if(result>=k) return k;
        }
        return result;
    }

    long long countWays(vector<int> &count,long long k){
        int letters=0;
        for(int i=0;i<26;i++) letters+=count[i];

        long long ways=1;

        for(int i=0;i<26;i++){
            if(count[i]==0) continue;

            long long cur=ncr(letters,count[i],k);

            if(ways>=k || cur>=k){
                ways=k;
                break;
            }

            if(ways>k/cur){
                ways=k;
                break;
            }

            ways*=cur;
            if(ways>=k){
                ways=k;
                break;
            }

            letters-=count[i];
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        int n=s.size();

        char mid=' ';
        if(n%2) mid=s[n/2];

        vector<int> count(26,0);

        for(int i=0;i<n;i++){
            if(n%2 && i==n/2) continue;
            count[s[i]-'a']++;
        }

        for(int i=0;i<26;i++) count[i]/=2;

        string halfresult="";
        int half=n/2;

        for(int i=0;i<half;i++){

            bool ok=false;

            for(int j=0;j<26;j++){

                if(count[j]==0) continue;

                count[j]--;

                long long ways=countWays(count,k);

                if(ways>=k){
                    halfresult.push_back(char('a'+j));
                    ok=true;
                    break;
                }

                k-=ways;
                count[j]++;
            }

            if(!ok) return "";
        }

        string rev=halfresult;
        reverse(rev.begin(),rev.end());

        if(mid!=' ') halfresult.push_back(mid);

        return halfresult+rev;
    }
};