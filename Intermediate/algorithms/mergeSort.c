void merge(int arr[], const int left[], const int right[], int leftLen, int rightLen)
{
    int i=0, j=0, k=0;

    while (i < leftLen && j < rightLen )
    {
        if (left[i] <= right[j] )
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < leftLen)
    {
        arr[k] = left[i];
        i++;k++;
    }
    while(j < rightLen )
    {
        arr[k] = right[j];
        j++;k++;
    }
}

void mergeSort(int arr[],int size)
{
    if (size <= 1) {return;}
    int leftLen = size / 2;
    int rightLen = size - leftLen;

    int left[leftLen],right[rightLen];

    for (int i=0; i < leftLen; i++)
    {
        left[i] = arr[i];
    }
    for (int j=0; j < rightLen; j++)
    {
        right[j] = arr[j + leftLen];
    }

    mergeSort(left, leftLen);
    mergeSort(right, rightLen);
    merge(arr, left, right, leftLen, rightLen);
}
