class Solution:
    def maxNumber(self, nums1, nums2, k):

        def max_subsequence(nums, k):
            drop = len(nums) - k
            stack = []

            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1

                stack.append(num)

            return stack[:k]

        def merge(a, b):
            result = []

            while a or b:
                if a > b:
                    result.append(a.pop(0))
                else:
                    result.append(b.pop(0))

            return result

        start = max(0, k - len(nums2))
        end = min(k, len(nums1))

        answer = []

        for i in range(start, end + 1):

            a = max_subsequence(nums1, i)
            b = max_subsequence(nums2, k - i)

            candidate = merge(a[:], b[:])

            answer = max(answer, candidate)

        return answer