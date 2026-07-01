class MinStack {
public:
    stack<long long>st;
    long long mini=0;
    MinStack(){

    };
    void push(int val)
    {
        if(st.empty())
        {
            mini=val;
            st.push(val);
        }
        else{
            if(val>=mini)
            {
                st.push(val);
            }
            else
            {
                st.push(2LL*val-mini);
                mini=val;
            }
        }
    }
    void pop()
    {
            if(st.empty())return;
            long long n=st.top();
            st.pop();
            if(n<mini)
            {
                mini=2LL*mini-n;
            }       
    }
    int top()
        {
            if(st.empty())return -1;
            long long x=st.top();
            if(mini<x)return x;
            else return mini;
        }
        int getMin()
        {
            return mini;
        }
    
     
};
