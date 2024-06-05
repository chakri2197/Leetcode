// Problem Link: https://leetcode.com/problems/get-equal-substrings-within-budget/  [1208. Get Equal Substrings Within Budget]

// sliding window approach with two pointers and dynamic window size should be used to solve this problem

// Brute force solution
// Time complexity: O(n^2)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include<string>
using namespace std;


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sub=0;
        if (maxCost==0){
            return 1;
        }

        for (int i=0; i<t.size();i++){
            int count =0;
            int j=i;
            int temp =maxCost;
            while(temp>0 && j<t.size()){
                cout<< "in while before cost change: " << temp << endl;
                
                temp-=abs(s[j]-t[j]);
                cout<< s[j] << " -> " << t[j] << endl;
                if(temp<0) break;
                cout<< "in while after cost change: " << temp << endl;
                count++;
                j++;
                cout<< "in while count: " << count << endl;
            }
            if(sub<count)
            sub = count;
            cout<< "out while count:" << sub << endl;
        }
        return sub;
    }
};

int main(){
    Solution obj;
    cout<< obj.equalSubstring("krpgjbjjznpzdfy","nxargkbydxmsgby",14);
    return 0;
}

//optimized solution

// sliding window approach with two pointers and dynamic window size
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currentsum=0;
        int count=0;
        int l=0, r=0;

        for ( r=0; r<t.size();r++){
             currentsum+=abs(s[r]-t[r]); // add until current sum is greater than maxCost
                          
             while(currentsum>maxCost){
                 currentsum-=abs(s[l]-t[l]); // remove from left until current sum is less than maxCost
                 l++;
                
             }
             count= max(count,r-l+1); // get the max length of substring
        
             
        }
        return count;
    }
};