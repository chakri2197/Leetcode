/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


// time complexity of this solution is O(log(min(n,m)))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Ensure nums1 is the smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Calculate the partition point
        int noEleLeft = (n1 + n2 + 1) / 2;
        int low = 0;
        int high = n1;
        
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = noEleLeft - mid1;
        
            // l1 is the maximum element on the left side of the partition in nums1
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            // l2 is the maximum element on the left side of the partition in nums2
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            // r1 is the minimum element on the right side of the partition in nums1
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            // r2 is the minimum element on the right side of the partition in nums2
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
            
            // Check if the current partition is correct
            if (l1 <= r2 && l2 <= r1) {
                // If the total number of elements is even
                if ((n1 + n2) % 2 == 0) {
                    // The median is the average of the two middle values
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    // If the total number of elements is odd
                    // The median is the maximum element on the left side of the partition
                    return (double)max(l1, l2);
                }
            } else if (l1 > r2) {
                // If l1 is greater than r2, move left in nums1
                high = mid1 - 1;
            } else {
                // If l2 is greater than r1, move right in nums1
                low = mid1 + 1;
            }
        }

        // If no valid partition is found (this should not happen in a valid input)
        return 0.0;
    }
};




// time complexity of this solution is O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Get sizes of both arrays
        int n = nums1.size();
        int m = nums2.size();
        
        // Create a merged array to store sorted elements from both arrays
        vector<int> merged(n + m);
        
        // Pointers for iterating through nums1 and nums2
        int i = 0;
        int j = 0;
        
        // Pointer for merged array
        int k = 0;
        
        // Merge nums1 and nums2 into merged array
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                merged[k] = nums1[i];
                i++;
            } else {
                merged[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        // If there are remaining elements in nums1, append them to merged array
        while (i < n) {
            merged[k] = nums1[i];
            i++;
            k++;
        }
        
        // If there are remaining elements in nums2, append them to merged array
        while (j < m) {
            merged[k] = nums2[j];
            j++;
            k++;
        }
        
        // Print merged array (optional)
        for (int x : merged) {
            cout << x << endl;
        }
        
        // Calculate the index of the median
        int mid = (n + m) / 2;
        
        // If the total number of elements is even, return the average of the two middle elements
        if ((n + m) % 2 == 0) {
            return (merged[mid] + merged[mid - 1]) / 2.0;
        } 
        // If the total number of elements is odd, return the middle element
        else {
            return merged[mid];
        }
    }
};
