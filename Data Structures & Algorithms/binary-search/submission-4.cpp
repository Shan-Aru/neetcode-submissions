class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        while(low<high)
        {
            int mid=(low+high)/2;
            if(target>nums[mid])low++;
            else if(target<nums[mid])high--;
            else return mid;
        }
        return -1;
    }
};
