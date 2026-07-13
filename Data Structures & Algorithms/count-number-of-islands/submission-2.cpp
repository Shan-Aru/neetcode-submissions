class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>&grid,
    vector<vector<int>>&vis,vector<pair<int,int>>&vec,int row0,int col0) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int nr=row+dr[k];
            int nc=col+dc[k];
            if(nr>=0 && nr<n &&
            nc>=0&&nc<m && !vis[nr][nc]&& grid[nr][nc]=='1')
            {
                dfs(nr,nc,grid,vis,vec,row0,col0);
            }
        }
    }   
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)); 
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&& grid[i][j]=='1'){
                    vector<pair<int,int>>vec;
                    cnt++;
                    dfs(i,j,grid,vis,vec,i,j);
                  
                }
            }
        }
        return cnt;
    }
};
