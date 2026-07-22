class Solution {
private:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(int row,int col,vector<vector<int>>&height,vector<vector<bool>>&visited)
    {
        int rows=height.size();
        int cols=height[0].size();
        visited[row][col]=true;
        for(int i=0;i<4;i++)
        {
            int nr=dr[i]+row;
            int nc=dc[i]+col;
            if(nr<0 ||nr>=rows ||nc<0||nc>=cols)continue;
            if(visited[nr][nc])continue;
            if(height[nr][nc]<height[row][col])continue;
            dfs(nr,nc,height,visited);

        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()||heights[0].empty())return {};
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>>pacific(row ,vector<bool>(col,false));
        vector<vector<bool>>atlantic(row,vector<bool>(col,false));
        for(int rows=0;rows<row;rows++)
        {
            dfs(rows,0,heights,pacific);
            dfs(rows,col-1,heights,atlantic);
        }
        for(int cols=0;cols<col;cols++)
        {
            dfs(0,cols,heights,pacific);
            dfs(row-1,cols,heights,atlantic);
        }
        vector<vector<int>>ans;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(pacific[i][j] && atlantic[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};
