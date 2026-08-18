class Solution {
private:
    void solve(int idx,vector<int>&nums,vector<int>&temp,
    vector<vector<int>>&ans)
    {
        ans.push_back(temp);
        for(int i=idx;i<nums.size() ;i++)
        {
            if(i>idx && nums[i-1]==nums[i])continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans);
        return ans;
    }
};
