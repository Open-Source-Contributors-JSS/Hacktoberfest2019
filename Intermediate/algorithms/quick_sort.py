def q_s(arr, start, end):
  if start < end:
    p_i = partition(arr, start, end)

    q_s(arr, start, p_i-1)
    q_s(arr, p_i+1, end)


def partition(arr, start, end):
  pivot = arr[end]
  i = start - 1
  for j in range(start, end):
    if arr[j] < pivot:
      i += 1
      arr[j], arr[i] = arr[i], arr[j]
  
  arr[i+1] , arr[end] = arr[end], arr[i+1]
  return i+1
  
if __name__ == '__main__':
  arr = [11, 105, 16, 187, 64, 70, 199, 68, 102, 139, 125, 190, 88, 67, 53, 61, 127, 17, 142, 96, 166, 20, 47, 131, 36]
  print(arr)
  print()
  q_s(arr, 0, len(arr)-1)
  print()
  print(arr)
