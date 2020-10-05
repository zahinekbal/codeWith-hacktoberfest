#include <stdio.h>    
     
int main()    
{    
    int m,i,n;
	
	printf("Enter number of elements in the array \n");
    scanf("%d", &m);
    //Initialize array     
    int arr[m];
	
    for (i = 0; i < m; i++)
    {
        printf("Enter integer no. %d  :", (i+1));
		scanf("%d", &arr[i]);
    }    
    //Calculate length of array arr    
    int length = sizeof(arr)/sizeof(arr[0]);
	   
	
    //n determine the number of times an array should be rotated    
    printf("Enter number of times to be left rotated\n");
    scanf("%d",&n);
        
printf("\n**********************\n");

    //Displays original array    
    printf("Original array: \n");    
    for (i = 0; i < length; i++) {     
        printf("%d ", arr[i]);     
    }      
        
    //Rotate the given array by n times toward left    
    for(i = 0; i < n; i++){    
        int j, first;    
        //Stores the first element of the array    
        first = arr[0];    
        
        for(j = 0; j < length-1; j++){    
            //Shift element of array by one    
            arr[j] = arr[j+1];    
        }    
        //First element of array will be added to the end    
        arr[j] = first;    
    }    
    printf("\n**********************\n");    
        
        
    //result after rotation    
    printf("Array after left rotation: \n");    
    for(i = 0; i < length; i++){    
        printf("%d ", arr[i]);    
    } 
     printf("\n**********************\n");
    return 0;    
}    
