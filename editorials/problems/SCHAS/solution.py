def LowerBound(arr, x, l, h):
    if h >= l:
        mid = (h + l) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return LowerBound(arr, x, l, mid - 1)
        elif(arr[mid] < x):
            return LowerBound(arr, x, mid + 1, h)
    else:
        return l


t = int(input())

for _ in range(t):
    n = int(input())
    height = list(map(int,input().split()))
    LIS = [height[0]]

    for i in range(1, n):
        if height[i] >= LIS[-1]:
            LIS += [height[i]]
        else:
            idx = LowerBound(LIS, height[i], 0, len(LIS) - 1)
            LIS[idx]=height[i]
    print(n - len(LIS))