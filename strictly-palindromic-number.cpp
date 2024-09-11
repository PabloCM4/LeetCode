    //  Link: https://leetcode.com/problems/strictly-palindromic-number/

class Solution {
public:
    bool isStrictlyPalindromic(int n) {

        bool answer = true;
        
        for(int i = 2; ( i < (n-1) ) && answer; i++)    //  Check every base until a false is found
        {
            int num = n, digit, j = 0;
            long long int n_based = 0, n_based_rev = 0;

            while(num)
            {
                digit = num%i;  //  Get the digit in base i
                n_based = (n_based * 10) + digit;   //  Put it at the most right
                n_based_rev += pow(10,j) * digit;   //  Put it at the most left
                num = num/i;    //  To get the following digit
                j++;    //  Used to get the digit to the left
            }

            answer = n_based == n_based_rev;    //  Check if palindromic
        }

        return answer;
    }
};