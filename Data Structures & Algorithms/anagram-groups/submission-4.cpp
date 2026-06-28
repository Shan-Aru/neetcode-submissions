#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(auto temp: strs)
        {
            string s=temp;
            sort(s.begin(),s.end());
            mpp[s].push_back(temp);
        }
        vector<vector<string>>res;
        for(auto temp: mpp)
        {
            res.push_back(temp.second);
        }
        return res;
    }
};
