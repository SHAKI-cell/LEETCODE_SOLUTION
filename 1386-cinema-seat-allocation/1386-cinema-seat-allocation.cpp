class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto &x :res){
            int row=x[0];
            int seat=x[1];
            mp[row].insert(seat);
        }
        int result=(n-mp.size())*2;
        for(auto &[row,bookseat]:mp){
            auto isavail=[&](int seat){
                return bookseat.find(seat)==bookseat.end();
            };
            bool groupA=isavail(2) && isavail(3) && isavail(4) && isavail(5);
            bool groupB=isavail(4) && isavail(5) && isavail(6) && isavail(7);
            bool groupC=isavail(6) && isavail(7) && isavail(8) && isavail(9);
            if(groupA && groupC){
                result+=2;
            } else if(groupA || groupB || groupC){
                result+=1;
            }

        }
        return result;
    }
};