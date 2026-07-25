class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int num:nums)
        {
            totalsum+=num;
        }
        if(totalsum%2!=0)return false;
        int target=totalsum/2;
        vector<int>dp(target+1,false);
        dp[0]=true;
        for(int num:nums)
        {
            for(int sum=target;sum>=num;sum--)
            {
                dp[sum]=dp[sum]||dp[sum-num];
            }
        }
        return dp[target];
    }
};
