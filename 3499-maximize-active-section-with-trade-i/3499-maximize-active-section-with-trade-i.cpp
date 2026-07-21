class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       int n=s.size();
       vector<int>in;
       int ac=count(begin(s),end(s),'1');
        int i=0;
        while(i<n){
           if(s[i]=='0'){
            int start=i;
            while(i<n && s[i]=='0') i++;
            in.push_back(i-start);
           } else{
              i++;
           }
        }
        int mxpair=0;
        for(int i=1;i<in.size();i++){
            mxpair=max(mxpair,in[i]+in[i-1]);
        }
        return mxpair+ac;
    }
};