/*
560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // key: number, value: times
        std::unordered_map<int, int> prefixSum{{0, 1}};
        int ret = 0;
        int acc = 0;
        for(int j = 0; j < nums.size(); ++j) {
            acc += nums[j];
            ret += prefixSum[acc - k];    
            prefixSum[acc]++;
        }
        return ret;
    }
};
