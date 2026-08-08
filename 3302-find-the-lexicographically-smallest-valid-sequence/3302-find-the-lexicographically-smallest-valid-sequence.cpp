class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
       int n1=word1.size();
       int n2=word2.size();
       vector<int>righthand(n1,0);
       int rightmatch=0;
       int i=n1-1;
       int j=n2-1;
       while(i>=0){
        if(j>=0 && word1[i]==word2[j]){
            rightmatch++;
            j--;
        }
       righthand[i]=rightmatch;
       i--;
       }
       vector<int>seq;
       bool changepower=true;
       i=0;
       j=0;
       while(i<n1 && j<n2){
           if(word1[i]==word2[j]){
            seq.push_back(i);
            j++;
           } else if(changepower==true && i+1<n1 && righthand[i+1]>=n2-j-1){
              seq.push_back(i);
              j++;
              changepower=false;
           }
           i++;
       }
       return j==n2 ? seq:vector<int>();
    }
};