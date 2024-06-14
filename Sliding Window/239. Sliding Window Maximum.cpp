

// BruteForce O(n*k)
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res; // Vector to store the maximum elements in each sliding window.
        int n = nums.size(); // Total number of elements in the array.

        int windowMax = INT_MIN; // Variable to store the maximum element in the current sliding window.

        // Iterate through the first sliding window of size 'k' to find the maximum element.
        for (int i = 0; i < k; i++) {
            windowMax = max(nums[i], windowMax);
        }

        // Add the maximum element of the first window to the result vector.
        res.push_back(windowMax);

        int i = 1; // Variable to track the current window's starting index.
        int l = 0; // Variable to track the current window's ending index.

        // Iterate through the rest of the array to slide the window.
        while (i < n - k + 1) {
            int curr = nums[i + k - 1]; // Current element entering the window.

            // If the element at 'l' (left boundary of the window) was the previous maximum, we need to recalculate 'windowMax'.
            if (nums[l] == windowMax) {
                windowMax = INT_MIN;
                // Iterate through the current window to find the maximum element.
                for (int j = i; j < i + k; j++) {
                    windowMax = max(nums[j], windowMax);
                }
            } else {
                // If the previous maximum is still valid, update 'windowMax' by comparing it with the new element entering the window.
                windowMax = max(nums[i + k - 1], windowMax);
            }

            l++; // Move the left boundary of the window to the right by one element.
            res.push_back(windowMax); // Add the maximum element of the current window to the result vector.
            i++; // Move to the next window.
        }

        return res; // Return the vector containing the maximum elements in each sliding window.
    }
};
