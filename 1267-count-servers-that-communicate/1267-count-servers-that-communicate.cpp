class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowInd(n,0);
        vector<int> colInd(m,0);

        for(int row = 0 ; row < n; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 1){
                    rowInd[row] += 1;
                    colInd[col] += 1;
                }
            }
        }

        int result = 0;
        for(int row = 0 ; row < n ;row++){
            for(int col = 0 ; col < m ;col++){
                if(grid[row][col] == 1 && (rowInd[row] > 1 || colInd[col] > 1)){
                    result++;
                }
            }
        }
        return result;
    }
};