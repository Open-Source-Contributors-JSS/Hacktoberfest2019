#include <iostream>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int *array, int length)
{
  for (int i = length - 1; i >= 0; --i)
    for (int j = 0; j < i; ++j)
      if (*(array + j) > *(array + j + 1))
        swap(array + j, array + j + 1);
}

int main(int argc, char const *argv[])
{
  int array[] = {78, 46, 3, 1, 56};
  bubble_sort(array, 5);
  for (auto i = 0; i < 5; ++i)
    std::cout << array[i] << " ";
  std::cout << std::endl;
  return 0;
}
