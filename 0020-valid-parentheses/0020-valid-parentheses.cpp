class Solution {
public:
    bool isValid(string s) {
        int n= s.size();
        if(n%2!=0) return false;
        stack<char>st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            } else{
                if(st.empty()) return false;
                char t1=st.top();
                st.pop();
                if(c==')' && t1=='(') continue;
                else  if(c=='}' && t1=='{') continue;
                else if(c==']' && t1=='[') continue;
                else return false;

            }
        }
        if(st.size()>=1) return false;
        return true;
    }
};