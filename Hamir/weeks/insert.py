# def insertion_sort(arr):
#     n = len(arr)

#     for i in range(1, n):
#         e = arr[i]

#         j = i-1

#         while j >= 0 and e > arr[j]:
#             arr[j+1] = arr[j]
#             j -= 1

#         arr[j+1] = e
        
#         print(*arr)

# n = int(input())
# a = list(map(int, input().split()))

# insertion_sort(a)

# Python program for implementation of Insertion Sort

# Function to do insertion sort
def insertionSort(arr):

	# Traverse through 1 to len(arr)
    for i in range(1, len(arr)):

        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

        arr.reverse()
        print(*arr)
        arr.reverse()


# Driver code to test above
n = int(input())
arr = list(map(int, input().split()))
insertionSort(arr)


# This code is contributed by Mohit Kumra
