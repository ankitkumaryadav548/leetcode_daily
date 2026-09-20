class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size() == 0) st.push(s[i]);
            else if(st.top() != s[i]) st.push(s[i]);
            else{  //st.top == s[i]
                st.pop();
            } 
        }
        string str = "";
        while(st.size()>0){
            str += st.top() ;
            st.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }
};