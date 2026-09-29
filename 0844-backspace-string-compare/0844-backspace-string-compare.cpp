class Solution {
public:
    bool backspaceCompare(string s, string t) {
       int n = s.size(); 
       int m = t.size();
       stack<char>st; 
       stack<char>pt;
       for(int i =0;i<n;i++){
        if(s[i] != '#') st.push(s[i]);
        else{
            if(st.size()>0)
            st.pop();
        }
       }
       for(int i =0;i<m;i++){
        if(t[i] != '#') pt.push(t[i]);
        else{
            if(pt.size()>0)
            pt.pop();
        }
       } 
       //now compare both stack
       if(st.size() != pt.size()) return false;
        while(st.size()>0){
            if(st.top() != pt.top()) return false;
            st.pop();
            pt.pop();
        }
       return true;
    }
};