    //  Link: https://leetcode.com/problems/different-ways-to-add-parentheses

//  Improvement: Save in memory the left and right expressions already calculated. See code below (not mine).
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) { 

        vector<int> answer;

        int exp_size = expression.size();

        //  If the expression is just two digits, return the answer with that value only
        if(exp_size < 3)
        {
            answer.push_back( stoi(expression) );
            return answer;
        }

        //  It will go through every position in the array searching for +, -, *
        for(int i = 0; i < exp_size; i++)
        {
            if( expression[i] < '0' )
            {
                //  When found, we will separate the string in two (left and right) to make it more simple
                char operator = expression[i];
                string left_exp = expression.substr(0, i);
                string right_exp = expression.substr(i+1);

                //  Saving the results of the left and right expression in this vectors
                vector<int> left_ans = diffWaysToCompute(left_exp);
                vector<int> right_ans = diffWaysToCompute(right_exp); 

                //  Now we just have to apply the operator with every solution of the left and right expressions
                for(int j = 0; j < left_ans.size(); j++)
                {
                    for(int k = 0; k < right_ans.size(); k++)
                    {
                        switch(operator)
                        {
                            case '+':
                                answer.push_back( left_ans[j] + right_ans[k] );
                                break;
                            case '-':
                                answer.push_back( left_ans[j] - right_ans[k] );
                                break;
                            case '*':
                                answer.push_back( left_ans[j] * right_ans[k] );
                                break;
                        }
                    }   //  for k
                }   //  for j

            }   //  if operator found
            
        }   //  for i

        return answer;

    }
};


/*
class Solution {
public:
    map<pair<int, int>, vector<int>> cache; //  Cache to save the already calculated values

    vector<int> diffWaysToCompute(string expression) {
        vector<int> exp;
        int idx = 0;
        expression += "+";

        //  It will change the string expression to put it in a vector<int>, changing + - * for negative values
        //  That way later we can use the cache we have created
        while (idx < expression.size())  {
            char c = expression[idx];
            char c1 = expression[idx + 1];
            char c2 = expression[idx + 2];
            if (c == '+') { exp.push_back(-1); idx += 1; }
            else if (c == '-') { exp.push_back(-2); idx += 1; }
            else if (c == '*') { exp.push_back(-3); idx += 1; }
            else if (c1 == '+' || c1 == '-' || c1 == '*') {
                exp.push_back(c - 48);
                idx += 1;
            }
            else if (c2 == '+' || c2 == '-' || c2 == '*') {
                int _c = c - 48;
                int _c1 = c1 - 48;
                exp.push_back(_c*10 + _c1);
                idx += 2;
            }
        }

        exp.pop_back();

        //  Now it calls the recursive function which actually solves the expression 
        return solve(exp, 0, exp.size() - 1);
    }

    //  Parameters for the recursive function are:
    //  -Expression to solve (always the same);
    //  -Start of the sub-expression we need to solve now
    //  -End of the sub-expression we need to solve now
    //  Very similar to my code but saving the results in cache
    vector<int> solve(vector<int>& exp, int start, int end) {
        vector<int> ans;

        //  if the expression is just a number, return it.
        if (start == end) {
            ans.push_back(exp[start]);
            return ans;
        }

        //  Go through every operator of the expression
        //  It is ensured it is a operator starting at i+1 and adding +2 every loop)
        for (int i = start + 1; i <= end; i += 2) {

            //  Check if the sub expression in left (start to i-1) is in cache, or solve it and save it
            if (cache[{start, i - 1}].size() == 0)
                cache[{start, i - 1}] = solve(exp, start, i - 1);

            //  Check if the sub expression in right (i+1 to end) is in cache, or solve it and save it.
            if (cache[{i + 1, end}].size() == 0)
                cache[{i + 1, end}] = solve(exp, i + 1, end);

            //  Once we have the left and right solved, let´s apply the operators and its done
            vector<int> lefts = cache[{start, i - 1}];
            vector<int> rights = cache[{i + 1, end}];
            int op = exp[i];
            for (auto left : lefts) {
                for (auto right : rights) {
                    if (op == -1) ans.push_back(left + right);
                    else if (op == -2) ans.push_back(left - right);
                    else if (op == -3) ans.push_back(left * right);
                }
            }
        }

        return ans;
    }
};
*/
