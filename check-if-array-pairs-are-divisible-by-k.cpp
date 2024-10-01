    //  Link:   https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        //  To store how frequent a remainder is
        vector<int> freq_remainder(k, 0);
        
        //  Calculate the remainder of every number and store how frequent it is
        for (int num : arr)
        {
            int remainder = ((num % k) + k) % k;  // Handle negative remainders
            freq_remainder[remainder]++;
        }
        //  We have to check that all remainders are paired (frequencies are the same in the extremes)

        //  Special case when the remainder is 0, it should be even as it cannot be paired with anything
        if (freq_remainder[0] % 2 != 0)
        {
            return false;
        }
        // Special case when k is even, the count of remainder k/2 must be even as it cannot be paired as well
        if (k % 2 == 0)
        {
            if (freq_remainder[k / 2] % 2 != 0)
            {
                return false;
            }
        }
        // Check all remainders from 1 to k/2 are paired (same frequency of the other extreme)
        for (int i = 1; i <= (k / 2); i++)
        {
            if (freq_remainder[i] != freq_remainder[k - i])
            {
                return false;
            }
        }
        
        return true;
    }
};