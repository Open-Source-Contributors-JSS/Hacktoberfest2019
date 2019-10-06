#include<iostream>
using namespace std;

bool primeOrNot(int num){

    if(num<=1){
        return false;
    }
    
    for(int i = 2; i<=num/2; i++){
        if(num % i == 0){
            return false;
        }else{
            return true;
        }
    }
}

int main(){
    int n;
    cin>>n;
    
    primeOrNot(n) ? cout<<"Prime" : cout<<"Not Prime";
    return 0;
}