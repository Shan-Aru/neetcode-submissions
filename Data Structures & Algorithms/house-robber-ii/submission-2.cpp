class Solution {
private:
    int helper(vector<int>&nums,int start,int end)
    {
        int prev1=0;
        int prev2=0;
        for(int i=start;i<=end;i++)
        {
            int current=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int n=nums.size();
        int a=helper(nums,0,n-2);
        int b=helper(nums,1,n-1);
        int ans=max(a,b);
        return ans;
    }
};
