class Solution {
public:
    int find(string s,vector<int>&cumm){
        int p1=stoi(s.substr(0,2));
        int p2=stoi(s.substr(3));
        return cumm[p1-1]+p2;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>monthdays={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int>cumm(13,0);
        cumm[1]=31;
        for(int i=2;i<=12;i++){
            cumm[i]=cumm[i-1]+monthdays[i-1];
        }
        int a1=find(arriveAlice,cumm);
        int a2=find(leaveAlice,cumm);
        int b1=find(arriveBob,cumm);
        int b2=find(leaveBob,cumm);
        int overlap=min(a2,b2)-max(a1,b1)+1;
        return overlap<0 ? 0: overlap;
    }
};