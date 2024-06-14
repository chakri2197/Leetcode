/*
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]
Constraints:

0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains only UTF-8 characters.
*/


#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(string s: strs){
            // Append the length of current string followed by '#' and the string itself
            res = res + to_string(s.size()) + "#" + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // Find the position of '#' which separates length and string
            while (s[j] != '#') {
                j++;
            }
            // Extract length of string from substring
            int length = stoi(s.substr(i, j - i));
            // Extract the string itself from substring
            string str = s.substr(j + 1, length);
            // Add the decoded string to result vector
            result.push_back(str);
            // Move the pointer to the next substring
            i = j + 1 + length;
        }
        
        return result;
    }
};
