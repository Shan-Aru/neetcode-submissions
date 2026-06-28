class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26]={0};
        int left=0;
        int maxfq=0;
        int ans=0;
        for(int right=0;right<s.length();right++)
        {
            count[s[right]-'A']++;
            maxfq=max(maxfq,count[s[right]-'A']);
            while((right-left+1)-maxfq>k)
            {
                count[s[left]-'A']--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
