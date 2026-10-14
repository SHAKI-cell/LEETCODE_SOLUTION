class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9) return "";
       vector<int>ans;
        int t1=sum/9;
        for(int i=0;i<t1;i++){
           ans.push_back(9);
        }
        int t2=sum%9;
       if(t2==0){
          t2=0;
       } else  {
      ans.push_back(t2);
       }
         while(ans.size()<num){
            ans.push_back(0);
         }
         string p="";
         for(int i=0;i<ans.size();i++){
            p+=to_string(ans[i]);
         }
        return p;
    }
};