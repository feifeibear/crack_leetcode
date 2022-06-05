# 152. Maximum Product Subarray
# Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
# 
# The test cases are generated so that the answer will fit in a 32-bit integer.
# 
# A subarray is a contiguous subsequence of the array.

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        
        @cache
        def dp(i: int)-> Tuple[int, int]:
            """
            return max, min
            """
            if i == 0:
                return (nums[i], nums[i])
            
            (maxv, minv) = dp(i-1)
            
            return (max(maxv*nums[i], nums[i], minv*nums[i]), 
                    min(maxv*nums[i], nums[i], minv*nums[i]))
        
        
        return max(dp(i)[0] for i in range(n))
        
