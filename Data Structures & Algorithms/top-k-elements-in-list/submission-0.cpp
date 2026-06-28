class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i:nums)
        {
            freq[i]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto it:freq)
        {
            bucket[it.second].push_back(it.first);
        }
        vector<int>result;
        for(int i=bucket.size()-1;i>=0 && result.size()<k;i--)
        {
            for(int n:bucket[i])
            {
                result.push_back(n);
                if(result.size()==k)return result;
            }
        }
        return result;
    }
};
