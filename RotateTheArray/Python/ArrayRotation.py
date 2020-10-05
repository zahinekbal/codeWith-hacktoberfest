#Python program for Array Rotation   
arr = [1, 2, 3, 4, 5];     
#n is the int value that determine times of rotation   
n = 3;    
     
#Rotating the array by n times   
for i in range(0, n):    
    #Storing the first element of the array in temp  
    temp = arr[0];    
        
    for j in range(0, len(arr)-1):    
        #Shift element by one position   
        arr[j] = arr[j+1];    
            
    #Adding temp in last index of arr    
    arr[len(arr)-1] = temp;    
     
print();    
     
#Printing Array after rotation    
print("Rotated Array is: ");    
for i in range(0, len(arr)):    
    print ("%d" % arr[i], end=" "),  