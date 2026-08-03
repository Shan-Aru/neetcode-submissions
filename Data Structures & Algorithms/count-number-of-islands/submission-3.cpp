class Solution {
private:
    void bfs(int row,int col,vector<vector<char>>&adj,vector<vector<int>>&vis)
    {
        int n=adj.size();
        int m=adj[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                !vis[nr][nc]&& adj[nr][nc]=='1')
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
                 
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
       if(grid.empty()||grid[0].empty())return 0;
       int n=grid.size();
       int m= grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int count=0;
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<m;j++)
            {
                 
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,vis);
            }
                   }
                          }
       return count;
    }
};
