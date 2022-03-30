class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int columns = matrix[0].size();
        int rows = matrix.size();
        int total = columns * rows;
        int counter = 0;
        
        int startingRow = 0;        
        int startingCol = 0;
        int endingRow = rows-1;
        int endingCol = columns -1;
        
        while(counter < total){
            
            // printing first row
            for(int i=startingCol;counter < total && i<=endingCol;i++){
                
                ans.push_back(matrix[startingRow][i]);
                counter++;
            }
            startingRow++ ;
            
            // printing last column
            for(int i=startingRow;counter < total && i<=endingRow;i++){
                
                ans.push_back(matrix[i][endingCol]);
                counter++   ;   
            }
            
            endingCol-- ;
            
            for(int i=endingCol;counter < total && i>=startingCol;i--){
                
                ans.push_back(matrix[endingRow][i]);
                counter++;
            }
            
            endingRow-- ;
            
            for(int i=endingRow;counter < total && i>=startingRow;i--){
                
                ans.push_back(matrix[i][startingCol]);
                counter++;
            }
            
            startingCol++;
               
            
        }
        return ans;
        
    }
};