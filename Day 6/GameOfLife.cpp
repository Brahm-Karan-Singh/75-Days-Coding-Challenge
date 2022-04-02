class Solution {
public:
  
    int countScore(vector<vector<int>> b, int row,int col,int rows,int columns){
        vector<vector<int>> dir {
            {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
        };
        int count = 0;
        
        for(vector<int> d:dir){
            int nrow = d[0] + row;
            int ncol = d[1] + col;
            
            if(nrow>=0 && nrow<rows && ncol>=0 && ncol<columns && (b[nrow][ncol] == 1 || b[nrow][ncol] == -1)){
                count ++;
            }
        }
        
        return count;        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        
        for(int i=0; i<rows; i++){
            for(int j=0;j<columns; j++){
                
                int count = countScore(board,i,j,rows,columns);
                
                if(count < 2 || count > 3 ){
                    
                    
                    if(board[i][j] == 1)
                        board[i][j] = -1;
                    else
                        board[i][j] = 0;
                }
                else if(count == 3 && board[i][j] == 0 ){
                    board[i][j] = 2;
                }
                
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
               
                board[i][j] = board[i][j] > 0? 1:0;
                
            }
        }
        
    }
};
