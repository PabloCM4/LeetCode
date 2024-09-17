    //  Link:   https://leetcode.com/problems/uncommon-words-from-two-sentences/

//  Improvement: Very inneficient. See better code below mine
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> answer;
        vector<string> words1;
        vector<string> words2;

        //  Add the words of sentence 1 to a vector to later be compared
        int word1_count = 0;
        words1.push_back("");
        for(char letter : s1)
        {
            if(letter == ' ')
            {
                word1_count++;
                words1.push_back("");
            }
            else words1[word1_count] += letter;
        }
        word1_count++;  //  To count last word which doesn´t have the space

        //  Add the words of sentence 1 to a vector to later be compared
        int word2_count = 0;
        
        words2.push_back("");
        for(char letter : s2)
        {
            if(letter == ' ')
            {
                word2_count++;
                words2.push_back("");
            }
            else words2[word2_count] += letter;
        }
        word2_count++;  //  To count last word which doesn´t have the space

        //  Create a vector of booleans so if we already found a duplicated a word, don´t search for it again
        vector<bool> found1(word1_count,false);
        vector<bool> found2(word2_count,false);

        //  Search of first sentence
        for(int i = 0; i < word1_count; i++)
        {
            string word_check = words1[i];
            bool found = false;
            //  Compare within the same sentece
            for(int j = i+1; ( j < word1_count ) && !found1[i]; j++)
            {
                if(word_check == words1[j])
                {
                    found = true;   //  Don´t end the search yet in case it is found multiple times
                    found1[j] = true;
                }
            }
             //  Compare with the other sentece
            for(int k = 0; ( k < word2_count ) && !found1[i]; k++)
            {
                if( word_check == words2[k] )
                {
                    found = true;   //  Don´t end the search yet in case it is found multiple times
                    found2[k] = true;
                }
            }

            if(found || found1[i]) found1[i] == true; 
            else answer.push_back( words1[i] );
        }
        
        //  Search of second sentence
        for(int i = 0; i < word2_count; i++)
        {
            string word_check = words2[i];
            bool found = false;
            //  Compare within the same sentece
            for(int j = i+1; j < word2_count ; j++)
            {
                if(word_check == words2[j])
                {
                    found = true;   //  Don´t end the search yet in case it is found multiple times
                    found2[j] = true;
                }
            }

            if(!found && !found2[i]) answer.push_back( words2[i] );
        }
        return answer;
    }
};

/*
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> word_map;
        vector<string> answer;
        string s12 = s1 + ' ' + s2;
        string word="";

        for(int i = 0; i < s12.size(); i++)
        {
            if(s12[i] == ' ')
            {
                word_map[word]++;   //  operator[] searches or inserts and intengers are initialized to 0 automatically
                word = "";          //  When we find a word, save it and add 1 to the count of that word
            }
            else
            {
                word += s12[i];
            }
        }
        word_map[word]++;   //  To add the last word which doesn´t have a space at the end

        for(auto &it: word_map)
        {
            if(it.second == 1)  //  If word only found once
            {
                answer.push_back(it.first);
            }
        }
        return ans;
    }
};
*/