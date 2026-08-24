class Solution {
private:
    int binarySearch(vector<int>&nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target)high=mid-1;
            else if(nums[mid]<target)low=mid+1;
            else return mid;
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]<=target && target<=matrix[i][matrix[0].size()-1])
            {
                if(binarySearch(matrix[i],target)!=-1)
                return true;
            }
        }
        return false;
    }
};
