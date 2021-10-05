import time, random, heapq


def numerosaleatorios():
    '''Genera una lista de mil cien numeros aleatorios'''
    v = []
    for i in range(1, 1000):
        num = int(random.randint(1, 500))
        v.append(num)
    return v


def heapsort(lst):
    """Ordena usando la libreria <heapq> incluida en python"""
    heap = list(lst)
    # Hace la lista una pila
    heapq.heapify(heap)
    # Los elementos  salen de la pila en orden ascendente
    for i in range(len(lst)):
        lst[i] = heapq.heappop(heap)


def calcularTiempo(metodo):
    def metodo_a_ejecutar(*argumentos):
        # Tiempo de inicio de ejecucion.
        t_inicial = time.time()
        # llamada al metodo a ejecutar.
        metodo(*argumentos)
        # Tiempo de fin de ejecucion.
        t_final = time.time()
        # Tiempo de ejecucion.
        tiempo_total = t_final - t_inicial
        # Devolvemos el tiempo de ejecucion.
        return tiempo_total

    # Devolvemos la funcion que se ejecuta.
    return metodo_a_ejecutar


def burbuja(v):
    """Metodo ordenamiento burbuja"""
    for i in range(len(v) - 1):
        for j in range(len(v) - 1):
            if v[j] > v[j + 1]:
                v[j], v[j + 1] = v[j + 1], v[j]


def ordenSeleccion(v):
    """Ordenamiento por seleccion"""
    for i in range(len(v) - 1):
        min_index = i
        for j in range(i + 1, len(v)):
            if v[min_index] > v[j]:
                min_index = j
        v[i], v[min_index] = v[min_index], v[i]


def quicksort(v, izq, der):
    """Metodo de ordenamiento QuickSort"""
    i = izq
    j = der
    x = v[(izq + der) / 2]
    while (i <= j):
        while v[i] < x and j <= der:
            i = i + 1
        while x < v[j] and j > izq:
            j = j - 1
        if i <= j:
            aux = v[i]
            v[i] = v[j]
            v[j] = aux
            i = i + 1
            j = j - 1

        if izq < j:
            quicksort(v, izq, j)
    if i < der:
        quicksort(v, i, der)


def HeapSort(A):
    """Metodo de ordenamiento HeapSort"""

    def heapify(A):
        start = (len(A) - 2) / 2
        while start >= 0:
            siftDown(A, start, len(A) - 1)
            start -= 1

    def siftDown(A, start, end):
        root = start
        while root * 2 + 1 <= end:
            child = root * 2 + 1
            if child + 1 <= end and A[child] < A[child + 1]:
                child += 1
            if child <= end and A[root] < A[child]:
                A[root], A[child] = A[child], A[root]
                root = child
            else:
                return

    heapify(A)
    end = len(A) - 1
    while end > 0:
        A[end], A[0] = A[0], A[end]
        siftDown(A, 0, end - 1)
        end -= 1


def shellSort(v):
    """Metodo de ordenamiento shell"""
    length = len(v)
    gap = int(length / 2)
    while gap >= 1:
        i = gap
        while i < length:
            value = v[i]
            j = i
            while j - gap >= 0 and value < v[j - gap]:
                v[j] = v[j - gap]
                j -= gap
            v[j] = value
            i += 1
        gap = int(gap / 2)


if __name__ == '__main__':
    print("El tiempo en segundos de los metodos de ordenamiento es: \n")

    tiempoBurbuja = calcularTiempo(burbuja)(numerosaleatorios())
    print("Ordenamiento Burbuja: %10.5f" % tiempoBurbuja)

    tiempoSeleccion = calcularTiempo(ordenSeleccion)(numerosaleatorios())
    print("Ordenamiento por Seleccion: %10.5f" % tiempoSeleccion)

    tiempoShell = calcularTiempo(shellSort)(numerosaleatorios())
    print("Ordenamiento Shell: %15.5f" % tiempoShell)

    tiempoHeapSort = calcularTiempo(HeapSort)(numerosaleatorios())
    print("Ordenamiento HeapSort: %10.5f" % tiempoHeapSort)

    tiempoHeapSortPython = calcularTiempo(heapsort)(numerosaleatorios())
    print("Ordenamiento HeapSort Python: %10.5f" % tiempoHeapSortPython)

    tiempoQuickSort = calcularTiempo(quicksort)(numerosaleatorios(), 0, len(numerosaleatorios()) - 1)
    print("Ordenamiento QuickSort: %10.5f" % tiempoQuickSort)
