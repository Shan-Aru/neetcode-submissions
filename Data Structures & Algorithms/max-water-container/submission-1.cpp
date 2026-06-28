class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxiarea=0;
        while(left<right)
        {
            int h=min(heights[left],heights[right]);
            int w=right-left;
            maxiarea=max(maxiarea,h*w);
            if(heights[left]<heights[right])left++;
            else right--;
        }
        return maxiarea;
    }
};
