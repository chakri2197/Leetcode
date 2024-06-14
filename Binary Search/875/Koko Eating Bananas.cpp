
/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109
*/

/*
    Given array of banana piles, guards are gone for h hours
    Return min int k such that can eat all banans within h
    Ex. piles = [3,6,7,11] h = 8 -> 4 (1@3, 2@6, 2@7, 3@11)

    Binary search, for each k count hours needed, store min

    Time: O(n x log m) -> n = # of piles, m = max # in a pile
    Space: O(1)
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); // Get the number of piles
        
        int l = 1; // Initial lower bound for binary search
        int r = *std::max_element(piles.begin(), piles.end()); // Initial upper bound for binary search
        // for (int i = 0; i < n; i++) {
        //     high = max(high, piles[i]);          // other way get max 
        // }
        int res = r; // Initialize result to the maximum eating speed
        
        // Binary search loop to find the minimum eating speed
        while (l <= r) {
            int mid = l + (r - l) / 2; // Calculate the middle eating speed
            
            long int count = 0; // Initialize count of hours needed to eat all bananas
            
            // Iterate through each pile and calculate the hours needed to eat them all at the current eating speed
            for (int i = 0; i < n; i++) {
                count += ceil((double)piles[i] / mid); // Add hours needed for current pile
            }
            
            // If the count of hours is less than or equal to available hours, update result and narrow the search to the left
            if (count <= h) {
                res = min(res, mid); // Update result if the current eating speed is smaller
                r = mid - 1; // Narrow the search to the left
            } else {
                l = mid + 1; // Narrow the search to the right
            }
        }
        
        return res; // Return the minimum eating speed
    }
};
