class Solution {
public:
    bool isonumeric(char ch)
    {
        if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0'&&ch<='9'))
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int left=0,right=s.length()-1;
        while(left<right)
        {
            if(!isonumeric(s[left]))
            {
                left++;
                continue;
            }
            if(!isonumeric(s[right]))
            {
                right--;
                continue;
            }
            if(tolower(s[left])!=tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
