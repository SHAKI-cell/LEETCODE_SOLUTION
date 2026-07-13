class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
          queue<int>pq;
          for(int i=1;i<=8;i++){
            pq.push(i);
          }
          vector<int>ans;
          while(!pq.empty()){
              int t1=pq.front();
              pq.pop();
            //   int t2=t1%10;
            //   int t3=t2+1;
            //   int t4=t1*10+t3;
              if(t1>=low && t1<=high){
                   ans.push_back(t1);
              }
               int t2=t1%10;
               if(t2+1<=9){
                pq.push(t1*10+(t2+1));
               }
          }
          return ans;
        // string ans="123456789";
        // int n=ans.size();
        //  vector<int>ans1;
        //  for(int i=2;i<10;i++){
        //     for(int j=0;j<=n-i;j++){
        //         int digit=stoi(ans.substr(j,i));
        //         if(digit>=low && digit<=high){
        //             ans1.push_back(digit);
        //         }
        //     }
        //  }
        //  return ans1;
    }
};