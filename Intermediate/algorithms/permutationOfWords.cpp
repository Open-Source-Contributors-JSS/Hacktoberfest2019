 /* INPUT:
  * 3 // number of words
  * I am you //words
  *
  * OUTPUT:
  * (I, am, you)
  * (I, you, am)
  * (am, I, you)
  * (am, you, I)
  * (you, I, am)
  * (you, am, I)
  */
 
 #include <iostream>
 #include <vector>
 using namespace std;
 
 void write_premutations(const vector<string>& words, vector<bool>& used, vector<string>& partialSolution, uint posToFill) {
     if (posToFill == words.size()) {
         cout << "(";
         for (uint i = 0; i < partialSolution.size(); ++i) {
             cout << partialSolution[i] << ((i != partialSolution.size() -1) ? ",":""); // condition ? expr1:expr2 means (do expr1 iff condition = true, do expr2 otherwise)
         }
         cout << ")" << endl;
     } else {
         for (uint i = 0; i < words.size(); ++i) {
             if (not used[i]) {
                 partialSolution[posToFill] = words[i];
                 used[i] = true;
                 write_premutations(words,used,partialSolution,posToFill + 1);
                 used[i] = false;
             }
         }
     }
 }
 
 int main() {
     int n; // number of words
     cin >> n;
     vector<string> perm(n);
     for (int i = 0; i < n; ++i) cin >> perm[i]; // write the n words you want, separated with a blank space
     vector<bool> used(n, false);
     vector<string> partialSolution(n);
     write_premutations(perm, used, partialSolution, 0);
 }
