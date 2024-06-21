#include <iostream>
#include <vector>
using namespace std;

int longestSubarrayWithSumAtMostK(vector<int>& nums, int k) {
    int left = 0, right = 0;  // Pointers to manage the sliding window
    int currentSum = 0;       // Current sum of elements in the sliding window
    int maxLength = 0;        // Maximum length of subarray with sum <= k

    while (right < nums.size()) {
        currentSum += nums[right];  // Expand the window by adding the right element

        // Shrink the window from the left if the current sum exceeds k
        while (currentSum > k && left <= right) {
            currentSum -= nums[left];
            left++;
        }

        // Update the maximum length of the subarray
        maxLength = max(maxLength, right - left + 1);

        right++;  // Move the right pointer to the next element
    }

    return maxLength;
}

int main() {
    vector<int> nums = {1, 8, 30, -5, 20, 7};  // Input array
    int k = 25;  // Target sum

    int result = longestSubarrayWithSumAtMostK(nums, k);
    cout << "The length of the longest subarray with sum at most " << k << " is: " << result << endl;

    return 0;
}

// Output: The length of the longest subarray with sum at most 25 is: 3