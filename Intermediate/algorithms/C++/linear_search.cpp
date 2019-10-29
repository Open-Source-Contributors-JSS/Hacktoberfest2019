#include <iostream>

int linear_search(int ar[], int n, int num) {
  int i;
  for(i=0;i<n;i++) {
    if(ar[i] == num) {
      return i;
    }
  }
  return -1;
}

int main(){
  int n;
  std::cout << "Enter number of elements:";
  std::cin >> n;
  int ar[n];
  
  std::cout << "Enter elements:";
  
  for(int i=0;i<n;i++) {
    std::cin >> ar[i];
  }
  
  int num;
  std::cout << "Enter number to look for:";
  std::cin >> num;
  
  int index = linear_search(ar, n, num);
  
  if(index == -1) {
    std::cout << num << " not found";
  }
  else {
    std::cout << num << " found on position " << index+1;
  }
}
