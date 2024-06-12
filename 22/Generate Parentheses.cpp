/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Public method to generate all combinations of well-formed parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> result; // Vector to store the result
        generate(n, 0, 0, "", result); // Call the recursive helper method
        return result; // Return the result vector
    }
    
private:
    // Helper method to generate parentheses recursively
    void generate(int n, int open, int close, string str, vector<string>& result) {
        // Base case: if the number of open and close parentheses both equal n, we have a valid combination
        if (open == n && close == n) {
            result.push_back(str); // Add the valid combination to the result
            return; // Return to explore other possibilities
        }
        // Recursive case 1: if the number of open parentheses is less than n, add an open parenthesis
        if (open < n) {
            generate(n, open + 1, close, str + '(', result); // Recur with one more open parenthesis
        }
        // Recursive case 2: if the number of open parentheses is greater than the number of close parentheses, add a close parenthesis
        if (open > close) {
            generate(n, open, close + 1, str + ')', result); // Recur with one more close parenthesis
        }
    }
};


/*
Intuition
This problem is one of the classical recursion problems.
For any given n, lets say n = 2, we have to fill four places in our output ("_ _ _ _"). And each of these places can be either filled by an open braces "(" or a closed braces ")".

Approach
                                "_  _  _  _"
                                / \     
                              '(' ')'
For every place we have two choices and 1 decision to make.
Our choices are to either use '(' or ')'.

Now lets try to visualize the recursive tree based upon the choices discussed above.

Initially, we have:
For n = 3
current ouput = ""
availableOpenBracketsCnt = 3 and availableCloseBracketsCnt = 3

The first choise is very simple. Since we can not start a balanced parenthesis sequence with ')', we have only one choice in the begining. So our output will be '(' and count of open brackets left = 2 and count of closed brackets left = 3.

                                    op      ip
                                    ""   O-3, C-3
                            
                                    "(",O-2,C-3
                    
                "((",O-1,C-3                            "()", O-2,C-2

    "(((",0,3             "(()",1,2                       "()(",1,2

    "((()",0,2      "(()(",0,2    "(())",1,1        "()((",0,2      "()()",1,1

    "((())",0,1     "(()()",0,1   "(())(",0,1       "()(()",0,1     "()()(",0,1

    "((()))",0,0   "(()())",0,0   "(())()",0,0      "()(())",0,0    "()()()", 0,0
                        

Observation from the recursive tree
1.Whenever we have count of open brackets equal to the count of close brackets, we have only one choice - that is to use '('. Because, all the brackets till now have been balanced. And we can not start a new sequence with ')'.
2.Whenever, count of close bracket is 0, we can only use '('.
3.Whenever, count of open bracket is 0, we can only use ')'.
4.And for all the remaining cases, we have both the choices.
5.We get an answer, when count of open == 0 and count of close == 0.
Just convert these 5 observations into an algorithm and write the code.

*/

class Solution {
public:
    void solve(string op, int open, int close, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        //when count of open and close brackets are same then 
        //we have only one choice to put open bracket 
        if(open == close){
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }
        else if(open == 0){
            //only choice is to put close brackets 
            string op1 = op;
            op1.push_back(')');
            solve(op1, open, close-1, ans);
        }
        else if(close == 0){
            //only choise is to use open bracket 
            string op1 = op;
            op1.push_back('(');
            solve(op1, open-1, close, ans);
        }
        else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(op1, open-1, close, ans);
            solve(op2, open, close-1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op = "";
        solve(op, open, close, ans);
        return ans;
    }
};