def merge(arr, left_half, right_half):
    i, j, k = 0, 0, 0
    inversions = 0
    left_len, right_len = len(left_half), len(right_half)
    while i < left_len and j < right_len:
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1
            inversions += left_len - i
        k += 1

    while i < left_len:
        arr[k] = left_half[i]
        i, k = i+1, k+1

    while j < right_len:
        arr[k] = right_half[j]
        j, k = j+1, k+1

    return inversions

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        left_half, right_half = arr[:mid], arr[mid:]

        inversions = merge_sort(left_half) + merge_sort(right_half) + merge(arr, left_half, right_half)
        return inversions
    return 0

def countInversions(arr):
    return merge_sort(arr)

if __name__ == "__main__":
    t = int(input().strip())
    for a0 in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split(' ')))
        print(countInversions(arr))
