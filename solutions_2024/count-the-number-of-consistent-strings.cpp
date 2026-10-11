    //  Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int answer = 0;
        for(int i = 0; i < words.size(); i++)   //  Go through every word
        {
            bool found = true;
            for(int j = 0; ( j < words[i].size() ) && found; j++)   //  Go through every letter of a word until a letter is not found
            {
                if (allowed.find(words[i][j]) == allowed.npos) found = false;
            }

            answer += found;    //  Add 0 or 1 depending if every letter has been found in allowed
        }
        return answer;
    }
};