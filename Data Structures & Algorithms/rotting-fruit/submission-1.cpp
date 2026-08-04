class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()|| grid[0].empty())return 0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)q.push({i,j});
                else if (grid[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        int time=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty() && fresh>0)
        {
            int size=q.size();
            while(size--)
            {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nr=dr[k]+row;
                int nc=dc[k]+col;
                if(nr>=0 && nr<n && nc>=0 && nc<m&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    fresh--;
                }
            }
            }
            time++;
        }
        if(fresh>0)return -1;
        return time;
    }
};
