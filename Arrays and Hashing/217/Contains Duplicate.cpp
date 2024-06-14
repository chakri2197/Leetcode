/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

// Time O(n) and space O(n)
#include <set> // Include the necessary header for set
class Solution {
public:
    // Function to check if the input vector contains any duplicate elements
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet; // Create an unordered_set to store unique elements

        // Iterate through each element in the input vector
        for(int i: nums) {
            // Check if the current element exists in the set
            if(mySet.find(i) != mySet.end()) {
                return true; // If the element exists, return true (duplicate found)
            } else {
                mySet.insert(i); // If the element doesn't exist, insert it into the set
            }
        }
        return false; // If no duplicates are found after iterating through all elements, return false
    }
};


// other way would be sorting array and compare adjacent elements Time O(nlogn) and Space O(1)