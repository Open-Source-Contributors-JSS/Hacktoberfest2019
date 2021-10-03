/* find the norm of a matrix using dynamic memory allocation*/
#include<stdio.h>  
#include<stdlib.h> 
#include<math.h> 


/*The driver code*/
int main(void)
{    
    int **array, *norm;        
    int i, j, m, n, max;    
    
    /*Taking the number of rows and colums from the user*/
    printf("Enter the number of rows and cols of matrix:");        
    scanf("%d%d", &m,&n);    
    
    /*dynamic memory allocation*/
    array=(int **)malloc(m*sizeof(int *));
    
    for(i=0;i<m;i++)           
    array[i]=(int *)malloc(n*sizeof(int));  
    
    /*dynamic memory allocation of the normal*/
    norm=(int *)malloc(n*sizeof(int));  
    
    for(i=0;i<n;i++)           
    norm[i]=0;        
    
    /*Taking the elements of the 2D matrix*/
    printf("Enter the elements of the matrix:");        
    for(i = 0; i < m; i++) 
    {                
        for(j = 0; j < n; j++) 
        {                        
            scanf("%d", &array[i][j]);                
            
        }        
        
    }        
    
    /*Algorithm for normal separation*/
    for(i = 0; i <m; i++) 
    {                
        for(j = 0; j <n; j++) 
        {                        
            norm[i] = norm[i] + array[j][i];
                
            
        }        
        
    }       
    
    max = norm[0];   
    
    /*Base case of max*/
    for(i = 0; i <m; i++) 
    {                
        if(max < norm[i]) 
        {                        
            max = norm[i];                
            
        }        
        
    }     
    
    
    /*Max of each colums */
    printf("Max(");     
    
    for(i = 0; i < n; i++) 
    {                
        printf("%d ", norm[i]);        
        
    }        
    printf(")\n"); 
    
    /*Final output*/
    printf("Norm of the given matrix is %d\n", max);        
    return 0;  
    
}
