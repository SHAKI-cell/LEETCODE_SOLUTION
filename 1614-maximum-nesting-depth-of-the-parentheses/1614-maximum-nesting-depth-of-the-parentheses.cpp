class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int res=0,curr=0;
        for(int i=0;i<n;i++){
            if(s.at(i)=='('){
                res=max(res,++curr);
            }
            if(s.at(i)==')'){
                curr--;
            }
        }
        return res;
    }
};