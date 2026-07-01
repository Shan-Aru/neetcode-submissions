class Solution {
public:
    bool isValid(string s) {   
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if((ch=='(') ||(ch=='{')|| (ch=='['))
            {
                st.push(ch);
            }
            else{
                if(st.empty())return false;
                if((st.top()=='(' && s[i]==')') ||
                (st.top()=='{' && s[i]=='}') ||
                (st.top()=='[' && s[i]==']') )
                    st.pop();
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
    
};
