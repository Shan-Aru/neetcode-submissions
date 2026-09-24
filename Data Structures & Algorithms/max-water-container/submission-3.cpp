class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxiarea=0;
        while(left<right){
            int w=right-left;
            int h=min(heights[left],heights[right]);
            int area=w*h;
            maxiarea=max(area,maxiarea);
            if(heights[left]<heights[right])left++;
            else right--;
        }
        return maxiarea;
    }
};
