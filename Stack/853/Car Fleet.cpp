
/*
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

 

Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

Output: 3

Explanation:

The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Example 2:

Input: target = 10, position = [3], speed = [3]

Output: 1

Explanation:

There is only one car, hence there is only one fleet.
Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]

Output: 1

Explanation:

The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
 

Constraints:

n == position.length == speed.length
1 <= n <= 105
0 < target <= 106
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 106
*/

/*
    n cars 1 road, diff pos/speeds, faster cars slow down -> car fleet, return # fleets
    Ex. target = 12, pos = [10,8,0,5,3], speeds = [2,4,1,1,3] -> 3 (10 & 8, 0, 5 & 3)

    Sort by start pos, calculate time for each car to finish, loop backwards
    If car behind finishes faster then catches up to fleet, else creates new fleet

    Time: O(n log n)
    Speed: O(n)
    space : O(n)
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Get the number of cars
        int n = speed.size();
       
        // Create a vector of pairs to store the positions and speeds of the cars
        vector<pair<int, int>> map(n, {0, 0});
        
        // Create a vector of pairs to store the positions and arrival times of the cars
        vector<pair<int, double>> stk;
        
        // Populate the map vector with the positions and speeds of the cars
        for(int i = 0; i < n; i++) {
            map[i] = {position[i], speed[i]};
        }

        // Sort the map vector based on the car positions
        sort(map.begin(), map.end());
        
        // Iterate over the cars from the end
        for(int i = speed.size() - 1; i >= 0; i--) {
            // Calculate the time taken for the current car to reach the target
            double time = double(target - map[i].first) / map[i].second;

            // Get the size of the stack
            int s = stk.size();
            
            // Check if the stack is not empty and the arrival time of the last car in the stack is less than the current car's arrival time
            if(s >= 1 && stk[s - 1].second < time) {
                // If true, add the current car to the stack
                stk.push_back({map[i].first, time});
            }
            // Check if the stack is empty
            else if(s == 0) {
                // If true, add the current car to the stack
                stk.push_back({map[i].first, time});
            }
        }
        // Return the number of car fleets
        return stk.size();
    }
};

// otherway

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Get the number of cars
        int n = position.size();
        
        // Create a vector of pairs to store the positions and arrival times of the cars
        vector<pair<int, double>> cars;
        
        // Calculate the arrival time for each car and store it in the vector of pairs
        for (int i = 0; i < n; i++) {
            double time = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        // Sort the cars based on their positions
        sort(cars.begin(), cars.end());
        
        // Initialize variables to track the maximum arrival time and the number of car fleets
        double maxTime = 0.0;
        int result = 0;
        
        // Iterate over the cars from the end
        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            // If the arrival time of the current car is greater than the maximum arrival time so far,
            // update the maximum arrival time and increment the number of car fleets
            if (time > maxTime) {
                maxTime = time;
                result++;
            }
        }
        
        // Return the number of car fleets
        return result;
    }
};

