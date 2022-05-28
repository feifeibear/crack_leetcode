/*
Leetcode Problem 3
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // substring is valid: its has no repeating char.
        unordered_map<char, int> substring_set;
        int ret = 0, left = 0;
        // A for loop move right forwards.
        for(int right = 0; right < s.length(); ++right) {
            substring_set[s[right]]++;
            // substring [left, right] is not valid
            // adjust left until valid
            while (substring_set[s[right]] > 1) {
                substring_set[s[left]]--;
                left++;
            }
            // if [left, right] is valid
            ret = std::max(right - left + 1, ret);
        }
        return ret;
    }
};
