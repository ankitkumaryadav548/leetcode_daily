
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            // Opening brackets → push into stack
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            // Closing brackets
            else {
                // If stack is empty, no opening bracket to match
                if(st.empty()) {
                    return false;
                }
                // Check matching brackets
                if(s[i] == ')' && st.top() == '(' ||
                   s[i] == ']' && st.top() == '[' ||
                   s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                // Brackets don't match
                else {
                    return false;
                }
            }
        }
        // Valid only when no opening brackets are left
        return st.empty();
    }
};