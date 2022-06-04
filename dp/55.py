# 55. Jump Game
# You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
# 
# Return true if you can reach the last index, or false otherwise.

class Solution:
    def canJump(self, nums: List[int]) -> bool:        
        n = len(nums)
        # can we jump from i to n-1
        @cache
        def dp(i) -> bool:
            if i >= n-1: return True
            if i + nums[i] >= n-1: return True
            
            for j in range(1, nums[i] + 1):
                if dp(i + j): return True
            
            return False
        
        return dp(0)
