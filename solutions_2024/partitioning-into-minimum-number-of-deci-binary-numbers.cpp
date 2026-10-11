    //  https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for(char digit : n)  //  The minimum deci-binary will be determined by the maximun digit of the string
        {
            if( (digit - 48) > max) max = (digit - 48);
        }

        return max;
    }
};