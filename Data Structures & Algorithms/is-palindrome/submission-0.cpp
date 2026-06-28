class Solution {
public:
    bool isalphanumeric(char ch)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int left=0,right=s.length()-1;
        while(left<right)
        {
            while(left<right && !isalphanumeric(s[left]))
                left++;
            while(left<right && !isalphanumeric(s[right]))
                right--;
            if(tolower(s[left])!=tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
