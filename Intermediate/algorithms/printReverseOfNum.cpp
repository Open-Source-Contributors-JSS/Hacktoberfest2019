#include<iostream>
using namespace std;

int main(){
    long long int num, reversed_num = 0, remainder;
    cout << "Enter an number: ";
    cin>>num;
    
    while(num != 0){
        remainder = num % 10;
        reversed_num = reversed_num * 10 + remainder;
        num = num/10;
    }

    cout << "Reversed Number = " << reversed_num;
    return 0;
}
