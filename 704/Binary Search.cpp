/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.

*/

// time complexity is O(logn) and space complexity is O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;                 // Initialize left boundary
        int r = nums.size() - 1;   // Initialize right boundary
        int mid;                   // Declare middle index variable
        
        while (l <= r) {           // Continue while the search space is valid
            //mid = (l + r) / 2;     // Calculate middle index
             mid = l + (r - l) / 2;  // Calculate middle index to avoid overflow
            

            if (nums[mid] == target) {  // If the middle element is the target
                return mid;             // Return the index
            }
            else if (nums[mid] > target) {  // If the middle element is greater than the target
                r = mid - 1;                // Move the right boundary to the left
            }
            else {                          // If the middle element is less than the target
                l = mid + 1;                // Move the left boundary to the right
            }
        }
        return -1;  // If the target is not found, return -1
    }
};
