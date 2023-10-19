def selection_sort(arr):
    # Traverse through all array elements
    for i in range(len(arr)):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # Swap the found minimum element with the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

    return arr

# Test
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original array:", arr)
sorted_arr = selection_sort(arr)
print("Sorted array:", sorted_arr)
