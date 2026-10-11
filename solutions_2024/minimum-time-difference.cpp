    //  Link:   https://leetcode.com/problems/minimum-time-difference/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int time_size = timePoints.size();

        vector<int> time_min(time_size);

        for(int i = 0; i < time_size; i++)
        {
            string hours = {timePoints[i][0], timePoints[i][1]};
            string minutes = {timePoints[i][3], timePoints[i][4]};

            int hours_int = stoi(hours);
            int minutes_int = stoi(minutes);
            
            time_min[i] = hours_int * 60 + minutes_int;
        }
        /*
        Better solution to convert to minutes:

        vector<int> vec(timePoints.size(),0);
        for(int i =0;i<timePoints.size();i++){
            string s = timePoints[i];
            int min=((s[0]-'0')*10 + (s[1]-'0'))*60 + (s[3]-'0')*10 + (s[4]-'0');
            vec[i]=min;
        }  
        
        */

        sort(time_min.begin(), time_min.end());

        int answer = INT_MAX;   //  Use this instead to avoid that last if: int answer = 1440 + vec[0] - vec[vec.size()-1];

        for(int i = 0; i < time_size - 1; i++)
        {
            if( ( time_min[i+1] - time_min[i] ) < answer ) answer = time_min[i+1] - time_min[i]; 
        }

        if( ( time_min[0] + 1440 - time_min[time_size-1] ) < answer ) answer = time_min[0] + 1440 - time_min[time_size-1];

        return answer;

    }
};