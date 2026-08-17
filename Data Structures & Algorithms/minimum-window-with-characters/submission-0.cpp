class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length())return ""; 
        int hash[256]={};
        for(int i=0;i<t.length();i++)
        {
            hash[t[i]]++;
        }
        int left=0,count=0,start=-1;
        int minlength=INT_MAX;
        for(int right=0;right<s.length();right++)
        {
            if(hash[s[right]]>0)count++;
            hash[s[right]]--;
            while(count==t.length())
            {
                if(right-left+1<minlength)
                {
                    minlength=right-left+1;
                    start=left;
                }
                hash[s[left]]++;
                if(hash[s[left]]>0)count--;
                left++;
            } 
        }
        if(start==-1)return "";
        return s.substr(start,minlength);
    }
};
