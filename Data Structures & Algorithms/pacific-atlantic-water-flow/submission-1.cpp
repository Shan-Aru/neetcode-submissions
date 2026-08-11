class Solution {
private:
    void dfs(int row,int col,vector<vector<bool>>&ocean,vector<vector<int>>& heights)
    {
        int n=ocean.size();
        int m=ocean[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        ocean[row][col]=true;
        for(int i=0;i<4;i++)
        {
            int nr=dr[i]+row;
            int nc=dc[i]+col;
            if(nr>=0&&nr<n&& nc>=0&& nc<m &&!ocean[nr][nc]&& 
            heights[nr][nc]>=heights[row][col])
            {
                dfs(nr,nc,ocean,heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if(heights.empty()||heights[0].empty())return {};
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            dfs(i,0,pacific,heights);
            dfs(i,m-1,atlantic,heights);
        }
        for(int i=0;i<m;i++)
        {
            dfs(0,i,pacific,heights);
            dfs(n-1,i,atlantic,heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]&& atlantic[i][j])ans.push_back({i,j});
            }
        }
        return ans;
        
    }
};
