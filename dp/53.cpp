/*
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, ans = INT_MIN;
        for(auto num : nums) {
            cur = cur < 0 ? num : cur+num;
            ans = max(ans, cur);
        }
        return ans;
    }
};
