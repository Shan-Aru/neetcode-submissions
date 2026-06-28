#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(string s:strs)
        {
            int count[26]={0};
            for(char c:s)
            {
                count[c-'a']++;
            }
            string key;
            key.reserve(26);
            for(int i=0;i<26;i++)
            {
                key+=char('a'+i);
                key+=char(count[i]);
            }
            mpp[key].push_back(s);
        }
        vector<vector<string>>result;
        for(auto &p:mpp)
        {
            result.push_back(p.second);
        }
        return result;
    }
};
