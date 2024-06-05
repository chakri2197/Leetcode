
"""
Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.

 

Example 1:

Input: word = "abcde"

Output: "1a1b1c1d1e"

Explanation:

Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.

For each prefix, append "1" followed by the character to comp.

Example 2:

Input: word = "aaaaaaaaaaaaaabb"

Output: "9a5a2b"

Explanation:

Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.

For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.
 

Constraints:

1 <= word.length <= 2 * 105
word consists only of lowercase English letters.

"""

class Solution:
    def compressedString(self, word: str) -> str:
        count=0
        l=[]
        i=0
        for c in word:
            if(i< len(word)-1):
                count+=1
                if(i==0):
                    i+=1
                    continue
                if(word[i-1]!=c):
                    if(count-1!=0):
                        l.append(str(count-1)+word[i-1])
                    count=1
                        #i+=1
                
                if(count>=9 and word[i-1]==c):
                    l.append(str(count)+c)
                    count=0
                    #i+=1
                i+=1
                
            else:
                if(word[i-1]!=c):
                    if(count!=0):
                        l.append(str(count)+word[i-1])
                    l.append("1"+c)
                elif(word[i-1]==c):
                    count+=1
                    l.append(str(count)+c)
        return ''.join(l)



# optimized solution
class Solution:
    def compressedString(self, word: str) -> str:
        if not word:
            return ""
        
        compstr = []
        n = len(word)
        i = 0
        
        while i < n:
            curr = word[i]
            c = 0
            
            while i < n and word[i] == curr and c < 9:
                c += 1
                i += 1
            compstr.append(f"{c}{curr}")
        return ''.join(compstr)