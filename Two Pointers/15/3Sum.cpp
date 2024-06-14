
/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/


// two pointer method Time: O(n^2)  and Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; // Vector to store the resulting triplets
        sort(nums.begin(), nums.end()); // Sort the input array
        
        int n = nums.size(); // Get the size of the input array

        // Iterate through the array
        for (int i = 0; i < n - 1; i++) {
            // Skip duplicate values at the outer loop
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            
            int l = i + 1; // Left pointer
            int r = n - 1; // Right pointer
            
            // Move the left and right pointers towards each other
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r]; // Calculate the sum of three elements
                
                // If the sum is zero, add the triplet to the result
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    
                    // Skip duplicate values at the inner loop
                    l++;
                    while (nums[l] == nums[l - 1] && l < r) {
                        l++;
                    }
                }
                // If the sum is greater than zero, move the right pointer towards the left
                else if (sum > 0) {
                    r--;
                }
                // If the sum is less than zero, move the left pointer towards the right
                else {
                    l++;
                }
            }
        }
        
        return res; // Return the resulting triplets
    }
};


// hashmap time O(n) and space O(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());     //Sorted Array
        if(nums.size() < 3){                // Base Case 1
            return {};
        }
        if(nums[0] > 0){                    // Base Case 2
            return {};
        }
        unordered_map<int , int> hashMap;
        for(int i = 0 ; i < nums.size() ; ++i){     //Hashing of Indices
            hashMap[nums[i]] = i;
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() - 2 ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            for(int j = i + 1 ; j < nums.size() - 1 ; ++j){     //Fixing another number after first number
                int required = -1*(nums[i] + nums[j]);    //To make sum 0, we would require the -ve sum of both fixed numbers.
                if(hashMap.count(required) && hashMap.find(required)->second > j){ //If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet.
                    answer.push_back({nums[i] , nums[j] , required});
                }
                j = hashMap.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = hashMap.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
        return answer;  //Return answer vector.
    }
};