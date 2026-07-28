class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>frequency(26);
        for(int i=0;i<s.size();i++)
        {
            frequency[s[i]-'a']=i;
        }
        int start=0;
        int end=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            end=max(end,frequency[s[i]-'a']);
            if(i==end)
            {
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};
