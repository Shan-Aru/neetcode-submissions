class Solution {
public:
    int reverse(int x) {
        int n=0;
        while(x!=0)
        {
            int ld=x%10;
            x=x/10;
            if(n>INT_MAX/10 ||(n==INT_MAX/10 && ld>7))return 0;
            if(n<INT_MIN/10||(n==INT_MIN/10 && ld>7))return 0;
            n=n*10+ld;
             
        }
        return n;
    }
};
