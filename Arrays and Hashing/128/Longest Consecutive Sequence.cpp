/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

// Time Complexity Analysis:
// Creating the unordered set from the input vector takes O(n) time complexity, where n is the number of elements in the input vector.
// Traversing through the set and performing constant-time operations (like checking for the existence of elements) takes O(n) time complexity in the worst case.
// Therefore, the overall time complexity of this solution is O(n).
// optimize time O(n) and space O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create an unordered set to store unique elements from the input vector
        unordered_set<int> s(nums.begin(), nums.end());
        int lcs = 0; // Initialize the length of the longest consecutive sequence

        // Iterate through each unique element in the set
        for (int num : s) {
            int curr = num;
            int loc = 1; // Initialize the length of the current consecutive sequence to 1
            
            // If the current number is the start of a consecutive sequence (no num - 1 in the set)
            if (!s.count(num - 1)) {
                // Keep incrementing curr and updating loc while curr + 1 exists in the set
                while (s.count(curr + 1)) {
                    curr++;
                    loc++;
                }
                // Update the length of the longest consecutive sequence
                lcs = max(loc, lcs);
            }
        }
        return lcs; // Return the length of the longest consecutive sequence
    }
};



// Sorting the array takes O(n log n) time complexity.
// Traversing the sorted array and comparing adjacent elements takes O(n) time complexity.
// Therefore, the overall time complexity of this solution is O(n log n) due to sorting.
// time (nlogn) and space O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0; // If the array is empty, return 0.
        }
        sort(nums.begin(), nums.end()); // Sort the array to make consecutive elements adjacent.
        int currentConsecutiveSequence = 1; // Initialize the length of the current consecutive sequence.
        int longestConsecutiveSequence = 0; // Initialize the length of the longest consecutive sequence.
        for (int i = 1; i < n; i++) {
            // If the current number is not equal to the previous one (avoid duplicates)
            if (nums[i] != nums[i - 1]) {
                // If the current number is consecutive to the previous one
                if (nums[i] == nums[i - 1] + 1) {
                    currentConsecutiveSequence++; // Increment the length of the current consecutive sequence.
                } else {
                    // If the current number is not consecutive, update the longest consecutive sequence and reset the current count.
                    longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                    currentConsecutiveSequence = 1;
                }
            }
        }
        // Update the longest consecutive sequence by comparing the current and previous counts.
        return max(longestConsecutiveSequence, currentConsecutiveSequence);
    }
};


// The search function has a time complexity of O(n), where n is the size of the input vector arr. This is because it performs a linear search through the vector.
// In the longestConsecutive function, for each element in the nums vector, the search function is called, resulting in O(n^2) time complexity, where n is the size of the input vector. This is because for each of the n elements, a linear search through the entire vector is performed.

// brute force time O(n^3) and space O(1)
class Solution {
public:
    // Function to search for a key in a vector
    bool search(vector<int> arr, int key) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == key) {
                return true;
            }
        }
        return false;
    }

    // Function to find the length of the longest consecutive sequence
    int longestConsecutive(vector<int>& nums) {
        int lcs = 0;  // Initialize the longest consecutive sequence length
        int n = nums.size();  // Get the size of the input vector
        for (int i = 0; i < n; i++) {
            int loc = 0;  // Initialize the length of the current consecutive sequence
            int curr_n = nums[i];  // Get the current number from the vector
            while (search(nums, curr_n)) {  // While the current number is found in the vector
                curr_n++;  // Move to the next number
                loc++;  // Increment the length of the consecutive sequence
            }
            if (loc > lcs) {  // Update the longest consecutive sequence length if needed
                lcs = loc;
            }
        }
        return lcs;  // Return the length of the longest consecutive sequence
    }
};
