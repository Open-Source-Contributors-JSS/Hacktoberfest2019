#include<iostream>
using namespace std;

int main(){
    //take the number and the number of places up to which the precision of root is desired
    int n, p;
    cin>>n>>p;

    int ans = 1, times = 0;
    float inc = 1;
    /*
        everything happening for calculating the face value of the root is repeated p number of times
        the increment is dynamic, since it depends on the order of the precision.
        for 1 decimal place, 0.1
        for 2, 0.01
        for 3, 0.001
        that means we need to divide this increment by 10, after every iteration
    */
    while(times <= p){

        while(ans*ans <= n){
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc/10;
        times++;
    }
    cout<<ans<<endl;
    return 0;
}
