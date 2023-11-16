import heapq
import random


class Sort:
    def __init__(self):
        pass

    def heapsort(self, arr):
        print("Initial", arr)
        self.__heapsort(arr)
        print("Final", arr)

    def __heapsort(self, arr):
        n = len(arr)
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(arr, n, i)

        for i in range(n - 1, 0, -1):
            self.swap(arr, 0, i)
            self.heapify(arr, i, 0)

    def heapify(self, arr, n, i):
        largest = i
        left = i * 2 + 1
        right = i * 2 + 2

        if left < n and arr[left] > arr[largest]:
            largest = left
        if right < n and arr[right] > arr[largest]:
            largest = right
        if i != largest:
            self.swap(arr, i, largest)
            self.heapify(arr, n, largest)

    def mergesort(self, arr):
        print("Initial:", arr)
        self.__mergesort(arr)
        print("Final:", arr)

    def __mergesort(self, arr):
        if len(arr) <= 1:
            return

        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        self.__mergesort(left)
        self.__mergesort(right)
        self.merge(arr, left, right)

    def merge(self, arr, left, right):
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

    def quicksort(self, arr):
        print("Before:", arr)
        self.__quicksort(arr, 0, len(arr) - 1)
        print("After:", arr)

    def __quicksort(self, arr, low, high):
        if low < high:
            i = self.partition(arr, low, high)
            self.__quicksort(arr, low, i)
            self.__quicksort(arr, i + 1, high)

    def partition(self, arr, low, high):

        pivot_index = low
        pivot_element = arr[pivot_index]
        i = low
        j = high

        while i < j:

            while i < len(arr) and arr[i] <= pivot_element:
                i += 1

            j -= 1
            while arr[j] > pivot_element:
                j -= 1

            if i < j:
                self.swap(arr, i, j)

        self.swap(arr, pivot_index, j)
        return j

    def swap(self, arr, i, j):
        arr[i], arr[j] = arr[j], arr[i]


if __name__ == '__main__':
    obj = Sort()
    arr = [random.randint(1, 200) for i in range(15)]
#
#     # obj.quicksort(arr)
    obj.heapsort(arr)


def quicksort(arr):
    def hoare_partition(arr, low, high):
        mid = low + (high - low) // 2

        # Determine the median of the first, middle, and last elements
        if arr[low] > arr[mid]:
            arr[low], arr[mid] = arr[mid], arr[low]
        if arr[low] > arr[high]:
            arr[low], arr[high] = arr[high], arr[low]
        if arr[mid] > arr[high]:
            arr[mid], arr[high] = arr[high], arr[mid]

        pivot = arr[mid]  # Median of three as the pivot
        i = low
        j = high

        while True:
            while arr[i] < pivot:
                i += 1
            while arr[j] > pivot:
                j -= 1

            if i >= j:
                return j

            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

    def quicksort_recursive(arr, low, high):
        if low < high:
            partition_index = hoare_partition(arr, low, high)
            quicksort_recursive(arr, low, partition_index)
            quicksort_recursive(arr, partition_index + 1, high)

    quicksort_recursive(arr, 0, len(arr) - 1)


# Example usage:
arr = [3, 6, 8, 10, 1, 2, 1]
quicksort(arr)
print(arr)

class Solution:
    def longestPalindrome(self, s: str) -> str:

        n = len(s)

        def selectLongest(s1, s2, s3):
            large = s1
            if len(large) < len(s2):
                large = s2
            if len(large) < len(s3):
                large = s3
            return large

        def func(start, end, r):

            if start >= 0 and end < n and s[start] == s[end]:
                r = s[start:end + 1]
                return selectLongest(func(start, end + 1, r),
                                     func(start - 1, end, r),
                                     func(start - 1, end + 1, r))

            return r

        res = ""
        for i in range(n):
            st = func(i, i, "")
            if len(st) > len(res):
                res = st

        return res


s = Solution()
print(s.longestPalindrome("babad"))