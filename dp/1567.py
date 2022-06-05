# 1567. Maximum Length of Subarray With Positive Product
# 
# Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
# 
# A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
# 
# Return the maximum length of a subarray with positive product.

class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        # dp[i] (maxlen positive, negative)
        
        n = len(nums)
        
        @cache
        def dp(i :int) -> Tuple[int, int]:
            """
            max len prod postive
            max len prod negative
            """
            
            if i == 0:
                return 1 if nums[i] > 0 else 0, 1 if nums[i] < 0 else 0
            
            if nums[i] > 0:
                if dp(i-1)[1] > 0:
                    return 1 + dp(i-1)[0], 1 + dp(i-1)[1]
                else:
                    return 1 + dp(i-1)[0], 0
            elif nums[i] < 0:
                if dp(i-1)[1] > 0:
                    return 1 + dp(i-1)[1], 1 + dp(i-1)[0]
                else:
                    return dp(i-1)[1], 1 + dp(i-1)[0]
            else:
                return 0, 0
            
        
        return max(dp(i)[0] for i in range(n))
            
