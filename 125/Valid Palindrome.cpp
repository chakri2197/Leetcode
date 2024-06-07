/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

*/


// Two pointer methid with time complexity O(n) and Space O(1)
#include <string> // Include the string header
#include <cctype> // Include the header for character classification functions

class Solution {
public:
    bool isPalindrome(string s) {
        int n = size(s); // Get the size of the input string
        int i = 0; // Initialize the left pointer
        string a; // Initialize a temporary string for storing alphanumeric characters

        // If the string is empty, it's considered a palindrome
        if (n == 0) {
            return true;
        }
        
        int j = n - 1; // Initialize the right pointer to the last index of the string

        // Loop until the left pointer is less than the right pointer
        for (i = 0; i < j;) {
            // Move the left pointer until it points to an alphanumeric character
            while (!isalnum(s[i]) && i < j) {
                i++;
            }
            
            // Move the right pointer until it points to an alphanumeric character
            while (!isalnum(s[j]) && i < j) {
                j--;
            }
            
            // If the characters at the left and right pointers are not equal (case insensitive), return false
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            
            // Move the pointers inward
            i++;
            j--;
        }
        
        // If the loop completes without finding any mismatch, the string is a palindrome
        return true;
    }
};
