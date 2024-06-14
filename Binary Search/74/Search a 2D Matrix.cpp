/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

// time complexity is O(logn * logm) and space complexity is O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;                               // Initialize left boundary
        int r = matrix.size() - 1;               // Initialize right boundary

        while (l <= r) {                         // Continue while the search space is valid
            int mid = (l + r) / 2;               // Calculate middle row index

            if (binarySearch(matrix[mid], target) == target) {  // If target found in current row
                return true;                    // Return true
            }
            else if (matrix[mid].back() > target) {  // If target could be in the current row
                r = mid - 1;                    // Update right boundary to search in upper rows
            }
            else {                              // If target could be in the rows below
                l = mid + 1;                    // Update left boundary to search in lower rows
            }
        }
        return false;                           // Return false if target not found
    }

private:
    int binarySearch(vector<int> sub, int target) {
        int l = 0;                             // Initialize left boundary
        int r = sub.size() - 1;                // Initialize right boundary

        while (l <= r) {                       // Continue while the search space is valid
            int mid = l + (r - l) / 2;         // Calculate middle column index to avoid overflow

            if (sub[mid] == target) {          // If target found in current row
                return sub[mid];               // Return the target
            }
            else if (target > sub[mid]) {      // If target could be in the right half
                l = mid + 1;                   // Update left boundary to search in right half
            }
            else {                             // If target could be in the left half
                r = mid - 1;                   // Update right boundary to search in left half
            }
        }
        return -1;                             // Return -1 if target not found
    }
};



/*
    Search for target value in matrix where every row & col is sorted

    Perform 2 binary searches: 1 to find row, then another to find col

    Time: O(log m + log n)
    Space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Initialize the boundaries for row binary search
        int lowRow = 0;
        int highRow = matrix.size() - 1;

        // Perform binary search to find the correct row
        while (lowRow < highRow) {
            int mid = lowRow + (highRow - lowRow) / 2; // Calculate mid index to avoid overflow

            // Check if the target is the first element of the mid row
            if (matrix[mid][0] == target) {
                return true; // Target found
            }

            // Check if the target is between the first elements of the mid row and the next row
            if (matrix[mid][0] < target && target < matrix[mid + 1][0]) {
                lowRow = mid; // Target is in the mid row
                break;
            }

            // If the target is greater than the first element of the mid row
            if (matrix[mid][0] < target) {
                lowRow = mid + 1; // Move to the lower half
            } else {
                highRow = mid - 1; // Move to the upper half
            }
        }

        // Initialize the boundaries for column binary search within the found row
        int lowCol = 0;
        int highCol = matrix[0].size() - 1;

        // Perform binary search within the row to find the target element
        while (lowCol <= highCol) {
            int mid = lowCol + (highCol - lowCol) / 2; // Calculate mid index to avoid overflow

            // Check if the mid element is the target
            if (matrix[lowRow][mid] == target) {
                return true; // Target found
            }

            // If the target is greater than the mid element
            if (matrix[lowRow][mid] < target) {
                lowCol = mid + 1; // Move to the right half
            } else {
                highCol = mid - 1; // Move to the left half
            }
        }

        return false; // Target not found in the matrix
    }
};

