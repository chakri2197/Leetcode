

/*
    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

/*
Given array of heights, return area of largest rectangle
Ex. heights = [2,1,5,6,2,3] -> 10 (5 x 2 at index 2 and 3)

Monotonic incr stack, if curr height lower extend back, find max area

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack to store pairs of indices and heights
        stack<pair<int,int>> stk;
        
        // Variable to store the maximum area
        int maxArea = 0;
        
        // Number of elements in the heights array
        int n = heights.size();
        
        // Loop through each element of the heights array
        for(int i = 0; i < n; i++) {
            // If the stack is not empty and the height of the current element
            // is less than the height of the element at the top of the stack
            if(!stk.empty() && stk.top().second > heights[i]) {
                // Width of the current rectangle
                int w = 0;
                
                // Pair to store the popped element from the stack
                pair<int,int> ele;
                
                // Pop elements from the stack until the height of the top element
                // is less than or equal to the height of the current element
                while(!stk.empty() && heights[i] < stk.top().second) {
                    ele = stk.top();  // Get the top element of the stack
                    stk.pop();        // Pop the top element
                    w = i - ele.first; // Calculate the width
                    maxArea = max(maxArea, ele.second * w); // Update maxArea
                }
                
                // Push the current element into the stack
                stk.push({ele.first, heights[i]});
            } else {
                // If the stack is empty or the height of the current element
                // is greater than or equal to the height of the element at the top of the stack,
                // push the current element into the stack
                stk.push({i, heights[i]});
            }
        }
        
        // Pop remaining elements from the stack and calculate the area
        while(!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            maxArea = max(maxArea, height * width);
        }
        
        // Return the maximum area
        return maxArea;
    }
};



// other way
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // pair: [index, height]
        stack<pair<int, int>> stk;
        int result = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();
                
                result = max(result, height * width);
                start = index;
            }
            
            stk.push({start, heights[i]});
        }
        
        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            
            result = max(result, height * width);
        }
                          
        return result;
    }
};



//correct halfway
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        //int minEle = 0;
        int n=heights.size();
        int width =1;
        int w=1;
        for(int i=0;i<n;i++){
            if(i>0){
                int A=width*heights[i];
                w++;
                int l=min(heights[i],heights[i-1]);
                int A1=l*w;

                if(A1>A and maxArea<A1){
                    maxArea=A1;
                }
                else if(A>=A1 and maxArea<A){
                    maxArea=A;
                    w=1;
                }

            }
            else
                maxArea=heights[0];
            
        }
        return maxArea;
    }
};