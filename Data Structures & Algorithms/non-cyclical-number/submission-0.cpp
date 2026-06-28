class Solution {
public:
    int getnext(int n)
    {
        int sum=0;
        while(n>0)
        {
            int rd=n%10;
            sum+=rd*rd;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1 && seen.find(n)==seen.end())
        {
            seen.insert(n);
            n=getnext(n);
        }
        return n==1;
    }
};
