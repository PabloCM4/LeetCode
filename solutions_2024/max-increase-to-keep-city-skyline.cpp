    //  Link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        int answer = 0, n = grid.size();
        
        vector<int> max_row(n, 0);  //  To save the maximun height of each row and column
        vector<int> max_col(n, 0);

        for(int i = 0; i < n; i++)  //  Go through every position of the grid, saving the maximum height of each row and column
        {
            for(int j = 0; j < n; j++)
            {
                max_row[i] = max( max_row[i], grid[i][j] );
                max_col[j] = max( max_col[j], grid[i][j] );
            }
        }

        for(int i = 0; i < n; i++)  //  Go through every position to start adding the answer now that we have all the info we need
        {
            for(int j = 0; j < n; j++)
            {
                answer += min( max_row[i], max_col[j] ) - grid[i][j];   //  Sums the minimum between the max height of the row and column we are in, so it doesn´t affect any.
            }
        }
        
        return answer;
    }
};