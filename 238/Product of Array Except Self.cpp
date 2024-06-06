/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/



// Time O(n) and space O(n+n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        vector<int> prefix(n,1);
        vector<int> postfix(n,1);
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1]; // prefix 1 1 2 6
        }
        
        for(int i=n-2;i>=0;i--){
            postfix[i]=postfix[i+1]*nums[i+1]; // postfix 24 24 12 4

        }
        
        for(int i=0;i<n;i++){
            res[i]=prefix[i]*postfix[i];
        }
        return res;
    }
};


// Time O(n) and space O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        
        int prefix=1;
        for(int i=0;i<n;i++){
           res[i]=prefix;
           prefix=prefix*nums[i];
          // cout << "prefix value : " << prefix << endl;
        }

        int postfix=1;
        for(int i=n-1;i>=0;i--){
            res[i]=(postfix*res[i]);
            postfix=postfix*nums[i];
            //cout << "psotfix value : " << postfix << endl;
        }
        return res;
    }
};