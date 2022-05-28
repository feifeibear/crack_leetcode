/*
424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

class Solution {
public:
    using Iter = unordered_map<char, int>::iterator;
    int _max_value(Iter begin_iter, Iter end_iter) {
        auto max_value = begin_iter->second;
        while(begin_iter != end_iter) {
            max_value = std::max(begin_iter->second, max_value);
            begin_iter++;
        }
        return max_value;
    }
    int characterReplacement(string s, int k) {
        // valid substr #substr - #max_cnt <= k     
        int ret = 0, left = 0;
        // key char, value times
        // get max cnt
        int max_cnt = 0;
        unordered_map<char, int> S_;
        for(int right = 0; right < s.size(); ++right) {
            auto right_key = s[right];
            S_[right_key]++;
            while(right - left + 1 - _max_value(S_.begin(), S_.end()) > k) {
                auto left_key = s[left];
                S_[left_key]--;
                left++;
            }
            ret = std::max(ret, right - left + 1);
        }
        return ret;
    }
};
