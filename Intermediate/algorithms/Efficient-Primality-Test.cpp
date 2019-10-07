// author : Harsh Vardhan (desert3agle)

#include <bits/stdc++.h>
using namespace std; 
  
bool isPrime(int n)  // complexity of O(√n)
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
  
  
int main() 
{   
    int T, n;
    cin >> T;  // no of test cases
    while(T--)
      {
       cin >> n;
       isPrime(n)?  cout << " true\n": cout << " false\n"; //ternary operators
      }
    return 0; 
} 
