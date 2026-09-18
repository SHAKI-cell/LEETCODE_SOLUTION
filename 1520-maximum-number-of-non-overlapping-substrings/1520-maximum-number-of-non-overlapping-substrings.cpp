class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>start(26,-1);
        vector<int>end(26,0);
        vector<bool>isvalid(26,false);
        vector<string>res;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(start[idx]==-1){
                start[idx]=i;
            }
            end[idx]=i;
        }
        for(int c=0;c<26;c++){
            if(start[c]==-1) continue;
               isvalid[c]=true;
            for(int i=start[c];i<=end[c];i++){
                if(start[s[i]-'a']<start[c]){
                    isvalid[c]=false;
                    break;
                }
                end[c]=max(end[c],end[s[i]-'a']);
            }
       }
       int last=INT_MAX;
       for(int i=n-1;i>=0;i--){
        int c=s[i]-'a';
        if(!isvalid[c]) continue;
        if(i==start[c] && end[c]<last){
            res.push_back(s.substr(i,end[c]-i+1));
            last=i;
        }
       }
       return res;
    }
};