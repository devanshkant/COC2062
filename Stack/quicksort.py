def partition(arr: list, left:int, right: int) -> int:
    pivot = arr[left]
    i, j = left, right
    while(i < j):
        while (i <= right - 1 and arr[i] <= pivot):
            i += 1
        while (j >= left + 1 and arr[j] > pivot):
            j -= 1
        if (i < j):
            arr[i], arr[j] = arr[j], arr[i]
    arr[left], arr[j] = arr[j], arr[left]
    return j
def qs(arr: list, left: int, right: int):
    if(left < right):
        partition_index = partition(arr, left, right)
        qs(arr, left, partition_index - 1)
        qs(arr, partition_index + 1, right)


    