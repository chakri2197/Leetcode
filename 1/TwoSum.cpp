
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/


// time complexity: O(n) and space complexity: O(n)
class Solution {
public:
    // Function to find two numbers in the 'nums' vector that sum up to the 'target'
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered map to store the mapping of each element to its index
        unordered_map<int,int> map;
        
        // Iterate through the 'nums' vector
        for(int i=0;i<nums.size();i++){
            // Calculate the complement of the current element required to achieve the target sum
            int ele = target - nums[i];

            // If the complement is not found in the map, store the current element and its index
            if(map.find(ele)==map.end()){
                map[nums[i]] = i;
            }
            // If the complement is found in the map, return the indices of the two elements
            else if(map.find(ele)!=map.end()){
                return {map[ele], i};
            }
        }
        
        // If no solution is found, return an empty vector
        return {};
    }
};

//other way

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // val -> index

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};