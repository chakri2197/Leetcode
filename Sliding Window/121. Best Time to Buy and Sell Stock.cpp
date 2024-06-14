/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Get the size of the prices array
        int n = prices.size();

        // Initialize variables for maximum profit, left pointer, and right pointer
        int profit = 0; // Maximum profit initialized to 0
        int l = 0; // Left pointer initially points to the first element
        int r = 1; // Right pointer initially points to the second element

        // If there are no prices, return 0 profit
        if(n == 0){
            return 0;
        }

        // Loop through the prices array
        while(r < n){
            
           
            // int e = prices[r] - prices[l];   // Calculate the profit between the prices at indices l and r
            // 
            // profit = max(e, profit);     // Update the maximum profit seen so far
            // 
            // if(e <= 0 and l < r){ // If the current profit is non-positive and l < r, move l to r
            //     l = r;
            // }


            // otherway to calculate
            if (prices[r] > prices[l])
                maxP = max(maxP, prices[r] - prices[l]);
            else
                l = r;

            
            r++; // Move the right pointer to the next element
        }
        
        // Return the maximum profit obtained
        return profit;
    }
};


//other ways to do it
int maxPro = 0; // Initialize maximum profit to 0
    int minPrice = INT_MAX; // Initialize minimum price to maximum possible integer value
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]); // Update minimum price seen so far
        maxPro = max(maxPro, prices[i] - minPrice); // Update maximum profit seen so far
    }
    return maxPro; // Return maximum profit
}