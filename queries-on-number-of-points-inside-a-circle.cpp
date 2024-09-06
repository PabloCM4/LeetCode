//  Link: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution {
public:

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {

        vector<int> answer(queries.size(), 0);
        float distance;
        for(int j=0; j < queries.size(); j++)
        {
            for(int i=0; i < points.size(); i++)
            {
                distance = pow( (queries[j][0] - points[i][0]), 2) + pow( (queries[j][1] - points[i][1]), 2);
                distance = sqrt(distance);
                if(distance <= queries[j][2]) answer[j]++;
            } 
        }

        return answer;
    }


};