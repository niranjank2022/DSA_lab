from types import *


class Solution:

    def sumCounts(self, nums: list[int]) -> int:
        n = len(nums)
        dp = {}
        return self.findSum(nums, dp, 0, n - 1)

    def findSum(self, arr, dp, start, end):
        if (start, end) in dp:
            return 0, dp[start, end][1]
        if start == end:
            dp[start, end] = arr[start], arr[start:end + 1]
            return arr[start], arr[start:end + 1]

        left = self.findSum(arr, dp, start, end - 1)
        right = self.findSum(arr, dp, start + 1, end)
        s, arr = self.merge(left[1], right[1])

        dp[start, end] = s + left[0] + right[0], arr
        return dp[start, end]

    def merge(self, left, right):
        i = j = 0
        arr = []
        s = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr.append(left[i])
                i += 1
            elif left[i] > right[j]:
                arr.append(right[j])
                j += 1
            else:
                arr.append(left[i])
                i += 1
                j += 1
            s += arr[-1]

        while i < len(left) and left[i] > arr[-1]:
            arr.append(left[i])
            i += 1
            s += arr[-1]

        while j < len(right) and right[j] > arr[-1]:
            arr.append(right[j])
            j += 1
            s += arr[-1]

        return s, arr


s = Solution()
print(s.sumCounts([1, 2, 1]))
print(s.sumCounts([1, 1]))
