/*
    There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

*/

// Time complexity is O(logn) and space complexity is O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        // Special case: If the array has only one element, check it directly
        if (r == 0) {
            return nums[0] == target ? 0 : -1;
        }

        // Special case: If the array has two elements, check them directly
        if (r == 1) {
            if (nums[0] == target) return 0;
            if (nums[1] == target) return 1;
            return -1;
        }

        // Perform binary search
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Check if the middle element is the target
            if (nums[mid] == target) {
                return mid;
            }

            // Determine which part of the array is sorted
            if (nums[l] <= nums[mid]) { // Left part is sorted
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Target is in the left part
                } else {
                    l = mid + 1; // Target is in the right part
                }
            } else { // Right part is sorted
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Target is in the right part
                } else {
                    r = mid - 1; // Target is in the left part
                }
            }
        }

        // Target not found
        return -1;
    }
};


// simpler solution

// Time complexity is O(logn) and space complexity is O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
