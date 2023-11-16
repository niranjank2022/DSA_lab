def ternary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2

        if arr[mid1] > target:
            right = mid1 - 1
        elif arr[mid2] < target:
            left = mid2
        else:
            left = mid1 + 1
            right = mid1 - 1

    return -1