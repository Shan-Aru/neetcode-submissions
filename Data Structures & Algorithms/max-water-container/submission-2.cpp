class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxarea=0;
        while(left<right)
        {
            int minheight=min(heights[left],heights[right]);
            int width=right-left;
            int area=minheight*width;
            maxarea=max(maxarea,area);
            if(heights[left]<heights[right])
            {
                left++;
            }
            else right--;
        }
        return maxarea;
    }
};
