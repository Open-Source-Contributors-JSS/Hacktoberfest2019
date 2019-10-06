#include<iostream>
using namespace std;

int main(){
    long long int num;
    cin>>num;
    
    while(num>=1){
        int rev = num%10;
        cout<<rev;
        num = num/10;
    }
    return 0;
}