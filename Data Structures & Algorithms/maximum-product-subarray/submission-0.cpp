class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentmax=nums[0];
        int currentmin=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)swap(currentmax,currentmin);
            currentmax=max(nums[i],currentmax*nums[i]);
            currentmin=min(nums[i],currentmin*nums[i]);
            ans=max(ans,currentmax);
        }
        return ans;
    }
};
