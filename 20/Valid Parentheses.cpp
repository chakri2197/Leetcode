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


// time complexity is O(n) and space complexity is O(n)
class Solution {
public:
    // Function to check if the input string of parentheses is valid
    bool isValid(string s) {
        stack<char> stk; // Stack to keep track of opening brackets

        // Iterate through each character in the string
        for (char c: s) {
            // If the character is an opening bracket, push it onto the stack
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else { // If the character is a closing bracket
                // Check if the stack is empty or the top of the stack does not match the current closing bracket
                if (stk.empty() || 
                    (c == ')' && stk.top() != '(') || 
                    (c == ']' && stk.top() != '[') || 
                    (c == '}' && stk.top() != '{')) {
                    return false; // Return false if there is a mismatch or the stack is empty
                } else {
                    stk.pop(); // Pop the top of the stack if it matches the current closing bracket
                }
            }
        }

        // If the stack is empty after processing all characters, the string is valid
        // Otherwise, it is invalid
        return stk.empty();
    }
};


/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false

    Stack of opens, check for matching closes & validity

    Time: O(n)
    Space: O(n)
*/

// hash table to store the mapping of closing brackets to opening brackets
// stack to store the opening brackets
// iterate through the string
// if the current character is a closing bracket

class Solution {
public:
    // Function to check if the input string of parentheses is valid
    bool isValid(string s) {
        stack<char> open; // Stack to keep track of opening brackets
        // Map to store the matching pairs of parentheses
        unordered_map<char, char> parens = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        // Iterate through each character in the string
        for (const auto& c : s) {
            // If the character is a closing bracket
            if (parens.find(c) != parens.end()) {
                // Check if the stack is empty, meaning there is no matching opening bracket
                if (open.empty()) {
                    return false;
                }
                // Check if the top of the stack does not match the current closing bracket
                if (open.top() != parens[c]) {
                    return false;
                }
                // Pop the top of the stack if it matches the current closing bracket
                open.pop();
            } 
            else { // If the character is an opening bracket, push it onto the stack
                open.push(c);
            }
        }
        
        // If the stack is empty after processing all characters, the string is valid
        // Otherwise, it is invalid
        return open.empty();
    }
};
