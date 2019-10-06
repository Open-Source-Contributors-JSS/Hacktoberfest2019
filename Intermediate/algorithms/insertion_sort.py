array = [97, 93, 95, 96, 92]


def insertionsort(array):
    for j in range(1, len(array)):
        KEY = array[j]
        i = j - 1
        while i >= 0 and array[i] > KEY:
            array[i + 1] = array[i]
            i = i - 1

        array[i + 1] = KEY


insertionsort(array)
print(array)
