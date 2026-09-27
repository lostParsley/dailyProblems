class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st ;
        int n  = size(s);
        string tp = "";
        for(int i = 0;i<n;i++){
            if(s[i] != ')' && s[i] != '('){
                tp += s[i];
            }

            else if(s[i] == '('){
                 st.push(tp);
                tp = "";
            }
            else {
                reverse(tp.begin() , tp.end());
                if(!st.empty()) {
                    tp = st.top() + tp;
                    st.pop();
                }
            }
        }
        return tp ; 
    }
};