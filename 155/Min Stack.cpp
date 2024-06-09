/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

// Time complexity is O(1) and space complexity is O(n)
class MinStack {

private:
    // Declare two stacks: one for storing all values, another for storing minimum values
    stack<int> stack1;
    stack<int> aStack;

public:
    // Constructor for MinStack
    MinStack() {
        // No initialization required as default constructor for stacks will be called
    }
    
    // Method to push a value onto the stack
    void push(int val) {
        // Push the value onto the main stack
        stack1.push(val);
        // If the auxiliary stack is empty or the new value is less than or equal to the top of the auxiliary stack,
        // push the new value onto the auxiliary stack as well
        if(aStack.empty()) {
            aStack.push(val);
        } else if (stack1.top() <= aStack.top()) {
            aStack.push(val);
        }
    }
    
    // Method to remove the top value from the stack
    void pop() {
        // If the top values of both stacks are the same, pop the value from the auxiliary stack
        if(stack1.top() == aStack.top()) {
            aStack.pop();
        }
        // Pop the value from the main stack
        stack1.pop();
    }
    
    // Method to get the top value of the stack
    int top() {
        return stack1.top();
    }
    
    // Method to get the minimum value in the stack
    int getMin() {
        return aStack.top();
    }
};





// other solution with pair
// Time complexity is O(1) and space complexity is O(n)

class MinStack {
private:
    // Use a single stack to store pairs of (value, current minimum)
    stack<pair<int, int>> s;

public:
    // Constructor for MinStack
    MinStack() {
        // No initialization required as default constructor for stack will be called
    }
    
    // Method to push a value onto the stack
    void push(int val) {
        if (s.empty()) {
            // If the stack is empty, push the value and the value itself as the current minimum
            s.push({val, val});
        } else {
            // If the stack is not empty, push the value and the minimum of the current value and the top's minimum
            s.push({val, min(val, s.top().second)});
        }
    }
    
    // Method to remove the top value from the stack
    void pop() {
        s.pop();
    }
    
    // Method to get the top value of the stack
    int top() {
        return s.top().first;
    }
    
    // Method to get the minimum value in the stack
    int getMin() {
        return s.top().second;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */