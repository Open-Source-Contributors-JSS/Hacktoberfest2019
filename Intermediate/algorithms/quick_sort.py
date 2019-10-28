def partition(ls, left, right):
    i = (left - 1)
    p = ls[right]
    for j in range(left, right):
        if ls[j] <= p:
            i = i + 1
            ls[i], ls[j] = ls[j], ls[i]
    ls[i + 1], ls[right] = ls[right], ls[i + 1]
    return i + 1


def quick_sort(ls, left, right):
    if left < right:
        m = partition(ls, left, right)
        quick_sort(ls, left, m - 1)
        quick_sort(ls, m + 1, right)
