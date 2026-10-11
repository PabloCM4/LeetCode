//  Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int window = 0, count_act = 0, count_max = 0, window_init = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1) window++;  //  Window size we need to fill with 1.
        }

        if( (window <= 1) ) return 0;
        else
        {
            for(int j = 0; j<=window; j++) nums.push_back(nums[j]); //  To create circular property

            for(int i=0; i<nums.size();i++)
            {
                if(i < window)  //  While in the window
                {
                    if(nums[i] == 1)    //  We count the 1
                    {
                        count_act++;
                        count_max++;
                    }
                }
                else // We need to move the window
                {
                    if( nums[window_init] == 1 ) count_act--;   //  If we move out of a 1, substract 1
                    window_init++;

                    if(nums[i] == 1) count_act++;   //  If we move into a 1, add 1.

                    if(count_act > count_max) count_max = count_act;
                }
            }
        }
        return (window-count_max);  //  Return the 0 we need to swap
    }
};