// time complexity: O(n)


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    vector<int> arr = {1, 8, 30, -5, 20, 7}; // Initialize the array with given elements
    
    int res = INT_MIN; // Initialize the result with the smallest possible integer
    int k = 3; // Length of the subarray
    int n = arr.size(); // Size of the array
    int curr = 0; // Current sum of the subarray
    
    // Calculate the sum of the first window of size k
    for (int i = 0; i < k; i++) {
        curr += arr[i];
    }
    
    res = max(res, curr); // Update the result with the maximum sum found
    
    // Slide the window to the right and update the current sum
    for (int i = k; i < n; i++) {
        curr = curr - arr[i - k] + arr[i]; // Update the current sum by removing the element at i-k and adding the element at i
        res = max(res, curr); // Update the result with the maximum sum found
    }
    
    cout << res << endl; // Print the maximum sum of any subarray of size k

    return 0;
}




// Another way to implement sliding window algorithm with fixed size window


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    vector<int> arr = {1, 8, 30, -5, 20, 7}; // Initialize the array with given elements
    
    int res = INT_MIN; // Initialize the result with the smallest possible integer
    int k = 3; // Length of the subarray
    int n = arr.size(); // Size of the array
    int curr = 0; // Current sum of the subarray
    int L = 0, R = 0; // Left and Right pointers for the sliding window
    
    for(int i = 0; i < n; i++) {
        // Build the initial window of size k
        while(i < k) {
            curr += arr[i]; // Add elements to the current window sum
            i++;
            R++;
            res = max(res, curr); // Update the result with the maximum sum found
            continue;
        }
        // Slide the window to the right
        curr = curr - arr[L] + arr[i]; // Update the current sum by removing the element at L and adding the element at i
        L++; // Move the left pointer to the right
        res = max(res, curr); // Update the result with the maximum sum found
    }
    cout << res << endl; // Print the maximum sum of any subarray of size k

    return 0;
}
