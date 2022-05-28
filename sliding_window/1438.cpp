/*
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Given an array of integers nums and an integer limit, 
return the size of the longest non-empty subarray such that 
the absolute difference between any two elements of this subarray is less than or equal to limit.
*/

class Solution {
public:
    
    int longestSubarray(vector<int>& nums, int limit) {
        // valid: substr abs diff between any 2 elem <= limit
        int left = 0;
        int ret = 0;
        // key: num, value: times it occurs in substr
        map<int, int> map_;
        for (int right = 0; right < nums.size(); ++right) {
            map_[nums[right]]++;
            // if not valid, move left until valid, O(logn) inseat ordered_map
            while(map_.rbegin()->first - map_.cbegin()->first > limit) {
                int left_key = nums[left];
                map_[left_key]--;
                if (map_[left_key] == 0) {
                    map_.erase(left_key);
                }
                left++;
            }
            ret = std::max(right - left + 1, ret);
        }
        /*
        time complexity O(nlogn)
        */
        return ret;
    }
};
