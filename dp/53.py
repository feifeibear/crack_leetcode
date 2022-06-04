# 53. Maximum Subarray
# 
# Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
# A subarray is a contiguous part of an array.

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        self.nums = nums
        return max([self.DP(i) for i in range(len(nums))])
    
    
    # DP[i] largest sum end at position i
    # DP[i] = max(DP[i-1] + nums[i], nums[i])
    @cache
    def DP(self, i) -> int:
        if i == 0:
            return self.nums[0]
        return max(self.DP(i - 1) + self.nums[i], self.nums[i])
