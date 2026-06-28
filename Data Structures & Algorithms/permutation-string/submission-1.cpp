class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;
        int s1map[26]={0};
        int s2map[26]={0};
        int n=s1.length();
        for(int i=0;i<n;i++)
        {
            s1map[s1[i]-'a']++;
            s2map[s2[i]-'a']++;
        }
        if(matches(s1map,s2map))return true;
        for(int i=n;i<s2.length();i++)
        {
            s2map[s2[i]-'a']++;
            s2map[s2[i-n]-'a']--;
            if(matches(s1map,s2map))return true;
        }
        return false;
    }
    bool matches(int a[],int b[])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])return false;
        }
        return true;
    }
};
