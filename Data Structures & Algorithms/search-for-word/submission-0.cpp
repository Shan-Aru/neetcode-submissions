class Solution {
private:
    bool solve( int row, int col,int idx,
    string word,vector<vector<char>>& board)
    {
        if(idx==word.size())return true;
        if(row<0||col<0||row>=board.size()||col>=board[0].size()
        || board[row][col]!=word[idx])return false;
        char temp=board[row][col];
        board[row][col]='#';
        bool found=solve(row+1,col,idx+1,word,board)||
                    solve(row-1,col,idx+1,word,board)||
                    solve(row,col+1,idx+1,word,board)||
                    solve(row,col-1,idx+1,word,board);
        board[row][col]=temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if (solve(i,j,0,word,board)) return true;
            }
        }
        return false;
    }
};
