/*

1								1	
1	2						2	1	
1	2	3				3	2	1	
1	2	3	4		4	3	2	1	
1	2	3	4	5	4	3	2	1	

*/

#include <iostream>
using namespace std;

int main() {
	int n,i,k,j;
	cin>>n;
	
	int rows = n;
	
	for(i = 1; i <= n; i++){
	    for(j = 1; j <= i; j++){
	        cout<<j<<"\t";
	    }j--;
	    
	    for(k = 1; k<=(2*rows - 3); k++){
	        cout<<"\t";
	    }rows--;
	    
	    if(i != n){
	        for(;j>0; j--){
	            cout<<j<<"\t";
	        }
	    }
	    
	    else if(i == n){
	        j--;
	        for(;j>0; j--){
	            cout<<j<<"\t";
	        }
	    }
	    
	    cout<<endl;
	}
	return 0;
}
