class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftknowsum=0;
        int rightknowsum=0;
        int leftques=0;
        int rightques=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    leftques++;
                } else{
                    rightques++;
                }
            } else {
                if(i<n/2){
                    leftknowsum+=num[i]-'0';
                } else{
                    rightknowsum+=num[i]-'0';
                }
            }
        }
      int total=leftques+rightques;
      if(total%2==1){
           return true;
      }
      int LEFT=2*leftknowsum+9*leftques;
      int RIGHT=2*rightknowsum+9*rightques;
      if(LEFT==RIGHT) return false;
      return true;

    }
};