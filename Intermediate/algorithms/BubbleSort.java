/* Bubblesort algorithm in Java
@Author: Rasmus Knoth Nielsen
 */
class BubbleSort
{
    // Method that implements the bubblesort algorithm
    void bubbleSort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                {
                    // swap arr[j+1] and arr[i]
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
    }

    // Method that prints out the array to the console
    void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Main method to test if the bubblesort works as intended.
    public static void main(String args[])
    {
        BubbleSort sort = new BubbleSort();
        int arr[] = {35, 13, 76, 9, 58, 39, 20, 1, 80, 55, 5};
        System.out.println("Array before being sorted:");
        sort.printArray(arr);
        sort.bubbleSort(arr);
        System.out.println("Array after being sortes:");
        sort.printArray(arr);
    }