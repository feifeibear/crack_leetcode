# 740. Delete and Earn

# You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
# 
# Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
# Return the maximum number of points you can earn by applying the above operation some number of times.

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        dict = {}
        for num in nums:
            if num not in dict:
                dict[num] = num
            else:
                dict[num] += num
        
        @cache
        def dp(n):
            if n == 1:
                if n in dict:
                    return dict[n]
                else:
                    return 0
            if n < 1:
                return 0
            
            if n in dict:
                return max(dp(n - 2) + dict[n], dp(n - 1))
            return dp(n - 1)
        
        return dp(2 * 10 ** 4)
