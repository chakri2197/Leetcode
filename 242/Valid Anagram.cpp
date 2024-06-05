/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/


// Time O(n) and space O(n)
#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    // Function to check if t is an anagram of s
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> map; // Create an unordered_map to count characters in s

        // If the length of s is less than the length of t, they cannot be anagrams
        if(s.length() != t.length()) {
            return false;
        }

        // Count the occurrences of each character in s
        for(char c : s) {
           
                map[c]++;
        }
    
        // Decrement the counts of characters in t
        for(char c : t) {
                map[c]--;                    
        }
        for(auto c:map){
            if(c.second!=0){
                return false
            }
        }
        return true;
    }
};



// time O(n) and space O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        
        // Count the frequency of characters in string s
        for (char x : s) {
            count[x - 'a']++;
        }
        
        // Decrement the frequency of characters in string t
        for (char x : t) {
            count[x - 'a']--;
        }
        
        // Check if any character has non-zero frequency
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        
        return true;
    }
};


// other soultion would be sort both s and t and compare its O(nlogn) and O(1)