/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/


// Time complexity is O(n) and space complexity is O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxi = 0; // Variable to store the maximum area
        int le = 0; // Left endpoint of the container
        int re = height.size() - 1; // Right endpoint of the container

        // Iterate while the left endpoint is less than the right endpoint
        while (le < re) {
            // Calculate the current height as the minimum of the heights at the left and right endpoints
            int l = min(height[le], height[re]);
            // Calculate the width of the container
            int w = re - le;
            // Update the maximum area if the current area is larger
            maxi = max((l * w), maxi);
            // Move the left endpoint to the right if the height at the left endpoint is less than or equal to the height at the right endpoint
            if (height[le] <= height[re]) {
                le++;
            }
            // Otherwise, move the right endpoint to the left
            else {
                re--;
            }
        }
        // Return the maximum area found
        return maxi;
    }
};



// time complexity : O(n^2) and space complexity : O(1)
// brute force solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l; // Variable to store the current height
        int w; // Variable to store the current width
        int n = height.size(); // Size of the input vector
        int maxi = 0; // Variable to keep track of the maximum area
        
        // Iterate over each pair of lines
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j > i; j--) {
                // Calculate the height of the container, which is the minimum height of the two lines
                l = min(height[i], height[j]);
                // Calculate the width of the container, which is the distance between the two lines
                w = j - i;
                // Calculate the area and update the maximum area if the current area is larger
                maxi = max((l * w), maxi);
            }
        }
        
        // Return the maximum area found
        return maxi;
    }
};

