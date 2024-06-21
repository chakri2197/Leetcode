
/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

// time complexity of this solution is O(n) and space complexity is O(n)
// this is a sliding window problem
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;  // Hashmap to store the last seen index of characters
        int n = s.size();  // Length of the input string

        int l = 0, r = 0;  // Left and right pointers for the sliding window
        int maxlen = 0;    // Maximum length of substring without repeating characters

        while (r < n) {
            // If the character at the right pointer is already in the map, remove characters from the left
            while (map.find(s[r]) != map.end() && l <= r) {
                cout << "in erase : " << s[l] << endl;
                map.erase(s[l]);  // Remove the character at the left pointer from the map
                l++;  // Move the left pointer to the right
            }

            // If the character at the right pointer is not in the map, add it to the map
            if (map.find(s[r]) == map.end()) {
                maxlen = max(maxlen, r - l+1);  // Update the maximum length of substring without repeating characters
                map[s[r]]++;  // Increment the count of the character in the map
                r++;  // Move the right pointer to the right
                
                cout << "len : " << maxlen << endl;
            }
        }

        return maxlen;  // Return the length of the longest substring without repeating characters
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    int result = sol.lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;
    return 0;
}


/*
Explanation:

Initialization:

1. map: An unordered map to store the last seen index of characters.
2. n: The length of the input string.
3. l, r: Left and right pointers for the sliding window.
4. maxlen: The maximum length of the substring without repeating characters.


Expanding the window:

1. Iterate through the string with the right pointer (r).
2. If the character at the right pointer is already in the map, remove characters from the left pointer (l) until the character at right is no longer in the map.


Updating the map:

1. If the character at the right pointer is not in the map, add it to the map and move the right pointer to the right.
2. Update maxlen with the current window size (r - l).


Iterate:

Continue moving the right pointer until the end of the string.
*/


// other way to implement this solution
class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        unordered_set<char> chars;
        int maxSize = 0;
        int i = 0, j = 0;
        while (j < s.size()){
            while (chars.find(s[j]) != chars.end()){
                chars.erase(s[i]);
                ++i;
            }
            maxSize = max(maxSize, j - i + 1);
            chars.insert(s[j]);
            ++j;
        }
        return maxSize;
    }
};