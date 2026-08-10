class Solution {
private:
    void dfs(int row, int col,vector<vector<char>>&grid)
    {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        grid[row][col]='0';
        for(int i=0;i<4;i++)
        {
            int nr=dr[i]+row;
            int nc=dc[i]+col;
            if(nr>=0 && nr<n && nc>=0&& nc<m&& grid[nr][nc]=='1')
            {
                dfs(nr,nc,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()|| grid[0].empty())return 0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
