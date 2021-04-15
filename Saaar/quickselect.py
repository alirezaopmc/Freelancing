def quick_select(arr, left, right, k):
    if left == right: return arr[left]

    pivot = arr[left]