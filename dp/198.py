# 198. House Robber
# You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
# 
# Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
# 
class Solution:
    def rob(self, nums: List[int]) -> int:
        # the max $ rober house i DP1[i]
        # the max $ not rober house i DP2[i]
        # DP1[i] = nums[i] + DP2[i-1]
        # DP2[i] = max(DP1[i-1], DP2[i-1])
        
        
        # 3 cases, R rober this house, N not rober this house, X do not care
        # i-2, i-1, i
        # X, N, R
        # N, R, N
        # R, N, N
        
        @cache
        def DP1(i):
            if i == 0:
                return nums[i]
            return nums[i] + DP2(i-1)
    
        @cache
        def DP2(i):
            if i == 0:
                return 0
            return max(DP1(i-1), DP2(i-1))
        
        return max(DP1(len(nums)-1), DP2(len(nums)-1))
