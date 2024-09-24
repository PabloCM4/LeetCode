    //  Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int answer = 0;
/*
        //  First idea, but very very unefficient
        //  Go through every arr1 number
        for( int i = 0; i < arr1.size(); i++)
        {
            //  Transform to string so we can access every digit in an easy way
            string s1 = to_string( arr1[i] );
            //  Same for arr2
            for( int j = 0; j < arr2.size(); j++)
            {
                string s2 = to_string( arr2[j] );
                int k = 0, prefix = 0;
                //  Count how many prefix they share
                while( ( k < s1.size() ) && ( k < s2.size() ) && ( s1[k] == s2[k] ) )
                {
                    prefix++;
                    k++;
                }
                if( prefix > answer) answer = prefix;
            }
        }
*/
        //  After reading the hints about using unordered set for the prefix in arr1

        unordered_set<int> prefix;
        //  Save all the possible prefix of arr1
        for(int elem1 : arr1 )
        {
            while(elem1 > 0)
            {
                prefix.insert(elem1);
                elem1 = elem1/10;
            }
        }

        //  Search every digit and element of arr2
        for(int elem2 : arr2)
        {
            while( ( elem2 > 0 ) && ( prefix.find(elem2) == prefix.end() ) )
            {
                elem2 = elem2/10;
            }
            int candidate = 0;

            //  When prefix is found, check the lenght of it and save it in case it is the max
            while( elem2 > 0)
            {
                candidate++;
                elem2 = elem2/10;
            }
            if( candidate > answer) answer = candidate;
            
        }
        return answer;
        
    }
};