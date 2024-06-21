/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/



// this is a sliding window problem
// time complexity of this solution is O(n^2) and space complexity is O(n)

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map, temp;

        // Create a frequency map for the characters in s1
        for (char c : s1) {
            map[c]++;
        }

        int n1 = s1.size();
        int n2 = s2.size();
        int l = 0, r = 0;

        while (r < n2) {
            temp = map;

            // If the current character in s2 exists in the map, start the sliding window
            if (map.find(s2[r]) != map.end()) {
                l = r;
                temp[s2[r]]--;

                r++;

                // Continue to slide the window while characters match and are in the map
                while (r < n2 && map.find(s2[r]) != map.end() && temp[s2[r]] > 0) {
                    temp[s2[r]]--;
                    r++;
                }

                // Check if the length of the current window matches the length of s1
                if (r - l == n1) {
                    return true;
                } else {
                    // Move the right pointer one step to the right and reset the window
                    r = l + 1;
                }
            } else {
                // If the current character is not in the map, move the right pointer one step to the right
                r++;
            }
        }
        return false;  // No permutation of s1 found in s2
    }
};

int main() {
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool result = sol.checkInclusion(s1, s2);
    cout << (result ? "True" : "False") << endl;
    return 0;
}
