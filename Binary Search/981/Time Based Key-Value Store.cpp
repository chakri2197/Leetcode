
/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
 

Constraints:

1 <= key.length, value.length <= 100
key and value consist of lowercase English letters and digits.
1 <= timestamp <= 107
All the timestamps timestamp of set are strictly increasing.
At most 2 * 105 calls will be made to set and get.
*/
class TimeMap {
public:
    // Constructor to initialize the TimeMap object
    TimeMap() {}

    // Method to set a key-value pair with a given timestamp
    void set(string key, string value, int timestamp) {
        // Append the value-timestamp pair to the vector associated with the key
        map[key].push_back({value, timestamp});
    }

    // Method to retrieve the value associated with a key at a given timestamp
    string get(string key, int timestamp) {
        string res = "";  // Initialize the result as an empty string

        // If the key does not exist in the map, return an empty string
        if (map.find(key) == map.end()) {
            return "";
        }

        // Perform a binary search on the vector of pairs to find the closest timestamp
        int l = 0;
        int r = map[key].size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;  // Calculate the middle index

            // If the timestamp at mid is less than or equal to the given timestamp,
            // store the value and move the left pointer to search for a potentially closer match
            if (timestamp >= map[key][mid].second) {
                res = map[key][mid].first;
                l = mid + 1;
            } else {
                // If the timestamp at mid is greater, move the right pointer
                r = mid - 1;
            }
        }

        // Return the result, which is the value associated with the closest timestamp
        return res;
    }

private:
    // Data structure to store the key-value pairs with timestamps
    // Uses an unordered_map where the key is a string and the value is a vector of pairs (value, timestamp)
    unordered_map<string, vector<pair<string, int>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */



// other solution
/*
    Design time-based key-value structure, multiple vals at diff times

    Hash map, since timestamps are naturally in order, binary search

    Time: O(log n)
    Space: O(n)
*/

class TimeMap {
public:
    // Constructor to initialize the TimeMap object
    TimeMap() {}

    // Method to set a key-value pair with a given timestamp
    void set(string key, string value, int timestamp) {
        // Append the timestamp-value pair to the vector associated with the key
        m[key].push_back({timestamp, value});
    }
    
    // Method to retrieve the value associated with a key at a given timestamp
    string get(string key, int timestamp) {
        // If the key does not exist in the map, return an empty string
        if (m.find(key) == m.end()) {
            return "";
        }
        
        // Perform a binary search on the vector of pairs to find the closest timestamp
        int low = 0;
        int high = m[key].size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Calculate the middle index
            if (m[key][mid].first < timestamp) {  // If the mid timestamp is less than the given timestamp
                low = mid + 1;  // Move the left pointer to mid + 1
            } else if (m[key][mid].first > timestamp) {  // If the mid timestamp is greater than the given timestamp
                high = mid - 1;  // Move the right pointer to mid - 1
            } else {  // If the mid timestamp is equal to the given timestamp
                return m[key][mid].second;  // Return the corresponding value
            }
        }
        
        // If the loop exits without finding an exact match, check if 'high' is within bounds
        if (high >= 0) {
            return m[key][high].second;  // Return the closest earlier timestamp's value
        }
        return "";  // If no valid timestamp is found, return an empty string
    }

private:
    // Data structure to store the key-value pairs with timestamps
    // Uses an unordered_map where the key is a string and the value is a vector of pairs (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */
