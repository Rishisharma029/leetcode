class Solution:
    def canPartition(self, nums):
        total = sum(nums)

        # If total sum is odd, can't split equally
        if total % 2 != 0:
            return False

        target = total // 2

        dp = [False] * (target + 1)
        dp[0] = True

        for num in nums:
            # Traverse backwards to avoid reusing the same element
            for j in range(target, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]

        return dp[target]
        