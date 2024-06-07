/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/


// 2 pointer solution with time O(n) and space O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Get the size of the input vector
        int n = numbers.size();
        
        // Initialize two pointers: one pointing to the start and another to the end of the vector
        int j = n - 1; // End pointer
        int i = 0;     // Start pointer
        
        // Loop until the start pointer crosses the end pointer
        for (; i < j;) {
            // Calculate the sum of the current elements pointed by the two pointers
            int sum = numbers[i] + numbers[j];
            
            // If the sum matches the target value, break out of the loop
            if (sum == target) {
                break;
            }
            // If the sum is greater than the target, decrement the end pointer
            else if (sum > target) {
                j--;
            }
            // If the sum is less than the target, increment the start pointer
            else {
                i++;
            }
        }
        
        // Return the indices (adjusted by 1) of the elements that sum up to the target
        return {i + 1, j + 1};
    }
};
