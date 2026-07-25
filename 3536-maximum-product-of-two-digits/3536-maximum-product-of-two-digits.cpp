class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n!=0){
            int digit=n%10;
            ans.push_back(digit);
             n/=10;
        }
        int p=*max_element(begin(ans),end(ans));
        int t=-1;
        int count=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==p) count++;
            else{
                t=max(t,ans[i]*p);
            }
        }
        if(count>1){
            t=max(t,p*p);
        }
        return t;
    }
};