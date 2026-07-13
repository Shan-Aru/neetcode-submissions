class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>&board)
    {
        int n=board.size();
        int m=board[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        board[row][col]='#';
        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&board[nr][nc]=='O')
            {
                dfs(nr,nc,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty())return;
        int n =board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
                dfs(i,0,board);
            if(board[i][m-1]=='O')
                dfs(i,m-1,board);
        }
        for(int i =0;i<m;i++)
        {
            if(board[0][i]=='O')
                dfs(0,i,board);
            if(board[n-1][i]=='O')
                dfs(n-1,i,board);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};
