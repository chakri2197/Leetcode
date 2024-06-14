
/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

// Time complexity is O(n) and space complexity is O(n)

class Solution {
public:
    // Function to perform basic arithmetic operations
    int opr(int e1, int e2, char c){
        if(c=='+')
            return e1 + e2;
        else if(c=='-')
            return e1 - e2;
        else if(c=='*')
            return e1 * e2;
        else // Assuming the input is always valid and won't cause division by zero
            return e1 / e2; // Integer division
    }
    
    // Function to evaluate the given Reverse Polish Notation expression
    int evalRPN(vector<string>& tokens) {
        stack<int> res; // Stack to hold operands during evaluation

        // Loop through each token in the expression
        for(string x: tokens){
            // If the token is a number, push it onto the stack
            if(x.size() > 1 || isdigit(x[0])){
                res.push(stoi(x));
            }
            // If the token is an operator, perform the operation on the top two operands on the stack
            else{
                // Pop the top operand from the stack and store it as the right operand
                int r = res.top();
                res.pop();
                // Pop the next operand from the stack and store it as the left operand
                int l = res.top();
                res.pop();
                // Perform the operation with the operands and operator, then push the result back onto the stack
                res.push(opr(l, r, x[0]));
            }
        }
        // The result is the only element left on the stack
        return res.top();
    }
};
