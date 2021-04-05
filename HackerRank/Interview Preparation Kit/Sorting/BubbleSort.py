def Bubble_Sort(arr, length) :
    count = 0
    for i in range(len(arr)) :
        for j in range(len(arr)-1) :
            if(arr[j] > arr[j+1]) :
                arr[j], arr[j+1] = arr[j+1], arr[j]
                count += 1
    return count

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
ans = Bubble_Sort(a, n)
print("Array is sorted in "+str(ans)+" swaps.")
print("First Element: "+str(a[0]))
print("Last Element: "+str(a[n-1]))
