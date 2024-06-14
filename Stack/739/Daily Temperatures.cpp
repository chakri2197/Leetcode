/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

// monotonic stack solution(stack with decreasing order of temperatures)
// Time complexity is O(n) and space complexity is O(n)

// The idea is to use a stack to keep track of the indices of the temperatures. 
//We iterate through the temperatures array and for each temperature, we check if it is higher than the temperature at the index stored 
//at the top of the stack. If it is, we calculate the number of days until warmer temperature for the temperature at that index 
//and update the result vector. We continue this process until we find a warmer temperature or the stack is empty. 
//Finally, we push the current index onto the stack and move to the next temperature.

class Solution {
public:
    // Function to calculate the number of days until warmer temperature for each day
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int s = temperatures.size(); // Size of the input temperatures array
        vector<int> res(s, 0); // Result vector initialized with zeros, same size as temperatures
        stack<int> stk; // Stack to store the indices of temperatures

        for (int i = 0; i < s; i++) { // Loop through each temperature
            // Check if the stack is not empty and the current temperature is higher than the temperature at the index stored at the top of the stack
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int j = stk.top(); // Get the index of the temperature from the top of the stack
                res[j] = i - j; // Calculate the number of days until warmer temperature for the temperature at index j
                stk.pop(); // Remove the index from the stack as it is no longer needed
            }
            stk.push(i); // Push the current index onto the stack
        }
        
        return res; // Return the result vector containing the number of days until warmer temperature for each day
    }
};





//brute force solution
// Time complexity is O(n^2) and space complexity is O(n)
class Solution {
public:
    // Function to calculate the number of days until warmer temperature for each day
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res; // Vector to store the result
        int s = temperatures.size(); // Size of the input temperatures array

        for (int i = 1; i < s; i++) { // Loop through each day's temperature starting from the second day
            if (temperatures[i] > temperatures[i - 1]) { // If the temperature of the current day is higher than the previous day
                res.push_back(1); // Push 1 to indicate one day until warmer temperature
            } else { // If the temperature of the current day is not higher than the previous day
                int j = i; // Index for iterating forward to find the next warmer day
                int count = 1; // Counter for number of days until warmer temperature
                while (j < s) { // Iterate forward through the temperatures array
                    if (temperatures[i - 1] >= temperatures[j]) { // If the current temperature is not warmer
                        count++; // Increment the counter for each day
                        j++; // Move to the next day
                    } else {
                        break; // Break out of the loop if a warmer day is found
                    }
                }
                if (j == s) // If no warmer day is found until the end of the temperatures array
                    res.push_back(0); // Push 0 to indicate no warmer day
                else
                    res.push_back(count); // Push the count of days until warmer temperature
            }
        }
        
        res.push_back(0); // Push 0 for the last day as there will be no warmer day
        return res; // Return the result vector
    }
};
