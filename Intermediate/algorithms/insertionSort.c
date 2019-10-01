void insertionSort(int A[], int size)
{
    for(int i=1; i<size; i++)
    {
        int value = A[i];
        int hole = i;
        while( hole>0 && A[hole-1]>value)
        {
            A[hole] = A[hole-1];
            hole--;
        }
        A[hole] = value ;
    }
}
