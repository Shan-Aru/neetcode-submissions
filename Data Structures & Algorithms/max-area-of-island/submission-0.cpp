class Solution {
private:
    int dfs(int row,int col,vector<vector<int>>&grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        grid[row][col] = 0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int area=1;
        for(int k=0;k<4;k++)
        {
            int nr=row+dr[k];
            int nc=col+dc[k];
            if(nr>=0&&nr<n && nc>=0&& nc<m &&grid[nr][nc]==1)
            {
                area+=dfs(nr,nc,grid);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()|| grid[0].empty())return 0;
        int n=grid.size();
        int m=grid[0].size();
        int maxarea=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int currentarea=dfs(i,j,grid);
                    maxarea=max(maxarea,currentarea);
                }
            }
        }
        return maxarea;
    }
};
