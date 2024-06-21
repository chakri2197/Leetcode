/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

// time complexity of this solution is O(n) and space complexity is O(1)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();  // Length of the input string
        int l = 0, r = 0;  // Left and right pointers for the sliding window
        int maxlen = 0;    // Maximum length of the substring with at most k replacements

        vector<int> count(26, 0);  // Frequency array for characters 'A' to 'Z'

        while (r < n) {
            count[s[r] - 'A']++;  // Increment the count of the current character
            // maxfreq = max(maxfreq, count[s[r] - 'A']);  // Update the maximum frequency of any character

            

            // Check if the current window is valid (number of replacements needed is less than or equal to k)
            while (r - l + 1 - *max_element(count.begin(), count.end()) /* -maxfreq */> k) { // instead  of *max_element(count.begin(), count.end()) 
                                                                                                //we can use maxfreq as we don't need to find max element again and again
                
                count[s[l] - 'A']--;  // Decrement the count of the left character
                l++;  // Shrink the window from the left
            }

            // Update the maximum length of the substring
            maxlen = max(maxlen, r - l + 1);
            r++;  // Expand the window by moving the right pointer
        }

        return maxlen;  // Return the maximum length of the substring found
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    int result = sol.characterReplacement(s, k);
    cout << "The length of the longest substring with at most " << k << " replacements is: " << result << endl;
    return 0;
}



// half solved
// time complexity of this solution is O(n) and space complexity is O(1)


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();  // Length of the input string
        int l = 0, r = 0;  // Left and right pointers for the sliding window
        int temp = k;  // Temporary variable to keep track of remaining replacements
        int maxlen = 0;  // Maximum length of substring with at most k replacements
        
        while (r < n) {
            // If characters at left and right pointers are the same, expand the window
            if (s[l] == s[r]) {
                maxlen = max(maxlen, r - l + 1);  // Update the maximum length
                r++;  // Move the right pointer to the right
                continue;  // Continue to the next iteration
            }
            // If characters are different and we still have replacements left
            else if (s[l] != s[r] && temp > 0) {
                maxlen = max(maxlen, r - l + 1);  // Update the maximum length
                r++;  // Move the right pointer to the right
                temp--;  // Use one replacement
                continue;  // Continue to the next iteration
            }

            // If characters are different and no replacements left, move the left pointer
            while (s[l] != s[r]) {
                l++;  // Move the left pointer to the right
            }

            // If no replacements left and the characters match, reset the temp variable
            if (temp <= 0 && s[r] == s[l]) {
                temp = k;  // Reset the replacement count
                r = l + 1;  // Move the right pointer to the position next to left pointer
            }
        }
        return maxlen;  // Return the maximum length of the substring found
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    int result = sol.characterReplacement(s, k);
    cout << "The length of the longest substring with at most " << k << " replacements is: " << result << endl;
    return 0;
}


