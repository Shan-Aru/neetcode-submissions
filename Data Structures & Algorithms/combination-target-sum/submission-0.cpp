class Solution {
private:
    void getallcombination(int idx,vector<int>&nums,vector<int>&combi,
    int target,vector<vector<int>>&ans)
    {
        if(target==0){
            ans.push_back(combi);
            return;
        }
        if(idx==nums.size() || target<0)return;
        combi.push_back(nums[idx]);
        getallcombination(idx,nums,combi,target-nums[idx],ans);
        combi.pop_back();
        getallcombination(idx+1,nums,combi,target,ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>combi;
        getallcombination(0,nums,combi,target,ans);
        return ans;
    }
};
