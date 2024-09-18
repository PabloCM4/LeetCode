    //  Link:   https://leetcode.com/problems/largest-number/

// Not my code. I tried to solve it for 2 hours without success. This was the solution I found.


//  Customized comparation to use it in the sort function. If AB > BA, then AB is good
bool mycompare(int a, int b)
{
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {

        string answer = "";
        
        sort(nums.begin(), nums.end(), mycompare);  //  Custom sort

        for(int number : nums)
        {
            answer+=to_string(number);  //  Once is sorted, just add one by one to the answer
        }

        if(answer[0] == '0') answer = "0";  //  Just for a specific test case

        return answer;
    }
};