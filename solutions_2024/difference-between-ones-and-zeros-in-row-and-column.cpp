    //  Link:   https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int size_row = grid.size();
        int size_col = grid[0].size();

        vector<int> ones_row(grid.size(), 0);   
        vector<int> ones_col(grid[0].size(), 0);

        vector<vector<int>> answer( size_row, vector<int>( size_col, 0 ) ); //  Improvement: We might can skip initializin to 0 as we are goin to overwrite anyways

        //  Count the ones in each row and col.
        for(int i = 0; i < size_row; i++)
        {
            for(int j = 0; j < size_col; j++)
            {
                if( grid[i][j] == 1 )
                {
                    ones_row[i]++;  //  Improvement: Instead of the if, add directly to the ones the number found in grid[i][j] 
                    ones_col[j]++;
                }
            }
        }

        //  Apply the equation given
        for(int i = 0; i < size_row; i++)
        {
            for(int j = 0; j < size_col; j++)
            {
                answer[i][j] = ones_row[i] + ones_col[j] - (size_row - ones_row[i]) - (size_col - ones_col[j]); //  I didn´t simplify the equation for better readibility
            }
        }

        return answer;

    }
};