# 45. Jump Game II
# Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
# 
# Each element in the array represents your maximum jump length at that position.
# 
# Your goal is to reach the last index in the minimum number of jumps.
# 
# You can assume that you can always reach the last index.

 

class Solution:
    def jump(self, nums: List[int]) -> int:
        # DP(i) min steps jump from i to n-1
        # dp(i + j) = dp(i) + 1 for j in range(1, nums[i])
        
        n = len(nums)
        @cache
        def dp(i):
            if i >= n-1: return 0
            if i + nums[i] >= n-1: return 1
            
            min_steps = 10**4+1
            for j in range(1, nums[i] + 1):
                min_steps = min(dp(i + j) + 1, min_steps) 
            
            return min_steps
        
        return dp(0)
