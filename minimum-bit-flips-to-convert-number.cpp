    //  Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int answer = 0;
    
        while( (start != 0) || (goal != 0) )    //  While there is still bits to compare
        {
            if( (start % 2) != (goal % 2) ) answer++;   //  If most right bit is different, we need to flip it
            start = start/2;    //  Deletes most right bit
            goal = goal/2;
        }
        return answer;
    }
};