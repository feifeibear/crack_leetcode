# 198. House Robber
# You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
# 
# Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
# 


class Solution:
    def rob(self, nums: List[int]) -> int:
        
        @cache
        def dp(i):
            """
            rober [0, i] house max gains
            """
            if i == 0:
                return nums[0]
            if i == 1:
                return max(nums[0], nums[1])
            
            return max(dp(i-1), dp(i-2) + nums[i])
        
        return dp(len(nums) - 1)
