class Solution {
private:
    void solve(int idx,vector<int>&nums, int target,
    vector<vector<int>>&ans,vector<int>&combi)
    {
        if(target==0)
        {
            ans.push_back(combi);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1])continue;
            if(nums[i]>target) break;
            combi.push_back(nums[i]);
            solve(i+1,nums,target-nums[i],ans,combi);
            combi.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combi;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,ans,combi);
        return ans;
    }
};
