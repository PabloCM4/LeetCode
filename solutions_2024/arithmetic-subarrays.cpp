    //  Link: https://leetcode.com/problems/arithmetic-subarrays/
    
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int m = l.size();
        //  Initialize everything to true and we try to find the false cases
        vector<bool> answer(m, true);

        for(int i = 0; i < m; i++)
        {
            //  If this query has two or less number, we can skip it, it is always true
            if( ( r[i] - l[i] ) >= 2 )
            {
                //  Get the numbers to solve (the end is exclusive, so we need to add 1)
                vector<int> query( nums.begin() + l[i], nums.begin() + r[i] + 1);

                int query_size = query.size();
                //  Sort the numbers so we have them in ascending order
                sort( query.begin(), query.end() );
                //  Get the original step for the arithmetic sequence
                int step = query[1] - query[0];
                //  Check every pair of number, stopping when the rule is broken
                for(int j = 1; j < (query_size - 1); j++)
                {
                    if( query[j+1] - query[j] != step )
                    {
                        answer[i] = false;
                        break;
                    }
                }
            }
        }

        return answer;

    }
};