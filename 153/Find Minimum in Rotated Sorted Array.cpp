/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

*/

// time complexity is O(logn) and space complexity is O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l=0;
        int r=nums.size()-1;
        int mid;
        if (r == 0)
            return nums[0];
        
        // If the array has two elements, return the smaller one
        if (r == 1) {
            return nums[0] > nums[1] ? nums[1] : nums[0];
        }
        
        // Perform binary search
        while (l < r) {
            int mid = l + (r - l) / 2;

            // If the middle element is greater than the rightmost element,
            // then the minimum element must be to the right of mid
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                // Otherwise, the minimum element is in the left half (including mid)
                r = mid;
            }
        }

        // The loop exits when l == r, which is the index of the smallest element
        return nums[l];
    }
};


// better solution
// Time complexity is O(logn) and space complexity is O(1)

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // Initialize result with the first element of the array
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        // Binary search to find the minimum element
        while (l <= r)
        {
            // If the subarray is already sorted, the leftmost element is the minimum
            if (nums[l] < nums[r])
            {
                res = min(res, nums[l]);
                break; // Exit the loop as we found the minimum
            }

            // Calculate mid to avoid overflow
            int mid = l + (r - l) / 2;

            // Update the result with the minimum value found so far
            res = min(res, nums[mid]);

            // If the middle element is greater than or equal to the left element,
            // it means the minimum is in the right part
            if (nums[mid] >= nums[l])
            {
                l = mid + 1; // Move the left pointer to the right of mid
            }
            else
            {
                // Otherwise, the minimum is in the left part
                r = mid - 1; // Move the right pointer to the left of mid
            }
        }

        return res; // Return the minimum element found
    }
};